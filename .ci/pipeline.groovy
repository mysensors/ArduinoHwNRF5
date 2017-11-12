#!groovy

def call(Closure body) {
	def config = [:]
	body.resolveStrategy = Closure.DELEGATE_FIRST
	body.delegate = config
	body()

	config.pr = load(config.repository_root+'.ci/pr-toolbox.groovy')
	def arduino  = load(config.repository_root+'.ci/arduino.groovy')

	if (env.CHANGE_ID) {
		config.is_pull_request = true
		echo "Building pull request: #"+env.CHANGE_ID+"\nTarget branch: "+env.CHANGE_TARGET
		config.git_sha = sh(returnStdout: true,
			script: """#!/bin/bash
								 cd ${config.repository_root}
								 git log -n 1 --pretty=format:'%H' refs/remotes/origin/PR-${env.CHANGE_ID}""").trim()
		config.pr.setBuildStatus(config, 'PENDING', 'Toll gate', 'Validating...', '${BUILD_URL}flowGraphTable/')
	} else {
		config.is_pull_request = false
		echo "Building branch: "+env.BRANCH_NAME
		config.git_sha = sh(returnStdout: true,
			script: """#!/bin/bash
								 cd ${config.repository_root}
								 git log -n 1 --pretty=format:'%H' refs/remotes/origin/${env.BRANCH_NAME}""").trim()
	}

	try {
		ansiColor('xterm') {
			if (config.is_pull_request) {
				def gitler = load(config.repository_root+'.ci/gitler.groovy')
				stage('Gitler') {
					gitler(config)
				}
			}

			parallel ArduinoBuilds: {
				lock(quantity: 1, resource: 'arduinoEnv') {
					stage('nRF52832 (tests,development)') {
						dir(config.library_root) {
							deleteDir()
						}
						checkout(changelog: false, poll: false, scm: [$class: 'GitSCM', branches: [[name: '*/development']],
							extensions: [
								[$class: 'CloneOption', depth: 0, noTags: false, reference: '', shallow: true],
								[$class: 'RelativeTargetDirectory', relativeTargetDir: config.library_root]
							],
							userRemoteConfigs: [[url: 'https://github.com/mysensors/MySensors.git']]])
						config.tests    = findFiles(glob: config.library_root+'tests/**/*.ino')
						config.examples = findFiles(glob: config.library_root+'examples/**/*.ino')
						arduino.buildnRF52832(config, config.tests, 'Tests-development')
					}
					stage('nRF52832 (examples,development)') {
						arduino.buildnRF52832(config, config.examples, 'Examples-development')
					}
					stage('nRF52832 (tests,master)') {
						dir(config.library_root) {
							deleteDir()
						}
						checkout(changelog: false, poll: false, scm: [$class: 'GitSCM', branches: [[name: '*/master']],
							extensions: [
								[$class: 'CloneOption', depth: 0, noTags: false, reference: '', shallow: true],
								[$class: 'RelativeTargetDirectory', relativeTargetDir: config.library_root]
							],
							userRemoteConfigs: [[url: 'https://github.com/mysensors/MySensors.git']]])
						config.tests    = findFiles(glob: config.library_root+'tests/**/*.ino')
						config.examples = findFiles(glob: config.library_root+'examples/**/*.ino')
						arduino.buildnRF52832(config, config.tests, 'Tests-master')
					}
					stage('nRF52832 (examples,master)') {
						arduino.buildnRF52832(config, config.examples, 'Examples-master')
					}
					stage('nRF51822 (tests,development)') {
						dir(config.library_root) {
							deleteDir()
						}
						checkout(changelog: false, poll: false, scm: [$class: 'GitSCM', branches: [[name: '*/development']],
							extensions: [
								[$class: 'CloneOption', depth: 0, noTags: false, reference: '', shallow: true],
								[$class: 'RelativeTargetDirectory', relativeTargetDir: config.library_root]
							],
							userRemoteConfigs: [[url: 'https://github.com/mysensors/MySensors.git']]])
						config.tests    = findFiles(glob: config.library_root+'tests/**/*.ino')
						config.examples = findFiles(glob: config.library_root+'examples/**/*.ino')
						arduino.buildnRF51822(config, config.tests, 'Tests-development')
					}
					stage('nRF51822 (examples,development)') {
						arduino.buildnRF51822(config, config.examples, 'Examples-development')
					}
					stage('nRF51822 (tests,master)') {
						dir(config.library_root) {
							deleteDir()
						}
						checkout(changelog: false, poll: false, scm: [$class: 'GitSCM', branches: [[name: '*/master']],
							extensions: [
								[$class: 'CloneOption', depth: 0, noTags: false, reference: '', shallow: true],
								[$class: 'RelativeTargetDirectory', relativeTargetDir: config.library_root]
							],
							userRemoteConfigs: [[url: 'https://github.com/mysensors/MySensors.git']]])
						config.tests    = findFiles(glob: config.library_root+'tests/**/*.ino')
						config.examples = findFiles(glob: config.library_root+'examples/**/*.ino')
						arduino.buildnRF51822(config, config.tests, 'Tests-master')
					}
					stage('nRF51822 (examples,master)') {
						arduino.buildnRF51822(config, config.examples, 'Examples-master')
					}
				}
			}, failFast: true
		}
	}	catch(ex) {
		currentBuild.result = 'FAILURE'
		throw ex
	} finally {
		if (currentBuild.result != 'SUCCESS')
		{
			config.pr.setBuildStatus(config, 'ERROR', 'Toll gate', 'Failed', '${BUILD_URL}flowGraphTable/')
			if (config.is_pull_request) {
				slackSend color: 'danger',
					message: "Job '${env.JOB_NAME} <${env.BUILD_URL}|#${env.BUILD_NUMBER}> <${env.CHANGE_URL}|PR#${env.CHANGE_ID} - ${env.CHANGE_TITLE}>' failed."
				emailext (
					subject: "Job '${env.JOB_NAME} #${env.BUILD_NUMBER}' failed",
					body: """Job '${env.JOB_NAME} <a href="${env.BUILD_URL}">#${env.BUILD_NUMBER}</a> (<a href="${env.CHANGE_URL}">PR#${env.CHANGE_ID} - ${env.CHANGE_TITLE}</a>)' ended with result ${currentBuild.result}.
					<br>Check attached console output or <a href="${env.BUILD_URL}">here</a> for a hint on what the problem might be.""",
					mimeType: 'text/html', to: env.CHANGE_AUTHOR_EMAIL, attachLog: true, compressLog: false
				)
			} else {
				slackSend color: 'danger',
					message: "Job '${env.JOB_NAME} <${env.BUILD_URL}|#${env.BUILD_NUMBER}> ${env.BRANCH_NAME}]' failed."
				emailext (
					subject: "Job '${env.JOB_NAME} #${env.BUILD_NUMBER} ${env.BRANCH_NAME}' failed",
					body: """Job '${env.JOB_NAME} <a href="${env.BUILD_URL}">#${env.BUILD_NUMBER}</a> (${env.BRANCH_NAME})' ended with result ${currentBuild.result}.
					<br>Check attached console output or <a href="${env.BUILD_URL}">here</a> for a hint on what the problem might be.""",
					mimeType: 'text/html', to: 'builds@mysensors.org', attachLog: true, compressLog: false
				)
			}
		}
		else
		{
			config.pr.setBuildStatus(config, 'SUCCESS', 'Toll gate', 'Pass', '')
		}
	}
}
return this
