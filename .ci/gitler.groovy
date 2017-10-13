#!groovy
def call(config) {
	config.pr.setBuildStatus(config, 'PENDING', 'Toll gate (Gitler)', 'Checking...', '${BUILD_URL}flowGraphTable/')

	dir(config.repository_root) {
		step([$class: 'GitChangelogRecorder', config: [configFile: 'git-changelog-settings.json',
			createFileTemplateContent: '''
{{#commits}}
{{{messageTitle}}}
{{/commits}}
''',
			createFileTemplateFile: '', createFileUseTemplateContent: true,
			createFileUseTemplateFile: false, customIssues: [[link: '', name: '', pattern: '', title: ''],
			[link: '', name: '', pattern: '', title: '']], dateFormat: 'YYYY-MM-dd HH:mm:ss',
			file: 'subjects.txt', fromReference: env.CHANGE_TARGET, fromType: 'ref', gitHubApi: '',
			gitHubApiTokenCredentialsId: '', gitHubIssuePattern: '#([0-9]+)', gitHubToken: '',
			gitLabApiTokenCredentialsId: '', gitLabProjectName: '', gitLabServer: '', gitLabToken: '',
			ignoreCommitsIfMessageMatches: '^Merge.*',
			ignoreCommitsWithoutIssue: false, ignoreTagsIfNameMatches: '',
			jiraIssuePattern: '\\b[a-zA-Z]([a-zA-Z]+)-([0-9]+)\\b', jiraPassword: '', jiraServer: '',
			jiraUsername: '', jiraUsernamePasswordCredentialsId: '', mediaWikiPassword: '',
			mediaWikiTemplateContent: '',	mediaWikiTemplateFile: '', mediaWikiTitle: '', mediaWikiUrl: '',
			mediaWikiUseTemplateContent: false, mediaWikiUseTemplateFile: false, mediaWikiUsername: '',
			noIssueName: 'No issue', readableTagName: '/([^/]+?)$', showSummary: false,
			showSummaryTemplateContent: '', showSummaryTemplateFile: '', showSummaryUseTemplateContent: false,
			showSummaryUseTemplateFile: false, subDirectory: '', timeZone: 'UTC',
			toReference: config.git_sha, toType: 'commit', untaggedName: 'Unreleased',
			useConfigFile: false, useFile: true, useGitHub: false, useGitHubApiTokenCredentials: false,
			useGitLab: false, useGitLabApiTokenCredentials: false, useIgnoreTagsIfNameMatches: false,
			useJira: false, useJiraUsernamePasswordCredentialsId: false, useMediaWiki: false,
			useReadableTagName: false, useSubDirectory: false]
		])
		step([$class: 'GitChangelogRecorder', config: [configFile: 'git-changelog-settings.json',
			createFileTemplateContent: '''
{{#commits}}
{{#messageBodyItems}}
{{.}} 
{{/messageBodyItems}}
{{/commits}}
''',
			createFileTemplateFile: '', createFileUseTemplateContent: true,
			createFileUseTemplateFile: false, customIssues: [[link: '', name: '', pattern: '', title: ''],
			[link: '', name: '', pattern: '', title: '']], dateFormat: 'YYYY-MM-dd HH:mm:ss',
			file: 'bodies.txt', fromReference: env.CHANGE_TARGET, fromType: 'ref', gitHubApi: '',
			gitHubApiTokenCredentialsId: '', gitHubIssuePattern: '#([0-9]+)', gitHubToken: '',
			gitLabApiTokenCredentialsId: '', gitLabProjectName: '', gitLabServer: '', gitLabToken: '',
			ignoreCommitsIfMessageMatches: '^Merge.*',
			ignoreCommitsWithoutIssue: false, ignoreTagsIfNameMatches: '',
			jiraIssuePattern: '\\b[a-zA-Z]([a-zA-Z]+)-([0-9]+)\\b', jiraPassword: '', jiraServer: '',
			jiraUsername: '', jiraUsernamePasswordCredentialsId: '', mediaWikiPassword: '',
			mediaWikiTemplateContent: '',	mediaWikiTemplateFile: '', mediaWikiTitle: '', mediaWikiUrl: '',
			mediaWikiUseTemplateContent: false, mediaWikiUseTemplateFile: false, mediaWikiUsername: '',
			noIssueName: 'No issue', readableTagName: '/([^/]+?)$', showSummary: false,
			showSummaryTemplateContent: '', showSummaryTemplateFile: '', showSummaryUseTemplateContent: false,
			showSummaryUseTemplateFile: false, subDirectory: '', timeZone: 'UTC',
			toReference: config.git_sha, toType: 'commit', untaggedName: 'Unreleased',
			useConfigFile: false, useFile: true, useGitHub: false, useGitHubApiTokenCredentials: false,
			useGitLab: false, useGitLabApiTokenCredentials: false, useIgnoreTagsIfNameMatches: false,
			useJira: false, useJiraUsernamePasswordCredentialsId: false, useMediaWiki: false,
			useReadableTagName: false, useSubDirectory: false]
		])
	}

	ret = sh(returnStatus: true,
		script:"""#!/bin/bash
							cd ${config.repository_root}/.ci
							./gitler.sh""")

	publishHTML([allowMissing: true, alwaysLinkToLastBuild: false, keepAll: true,
		reportDir: config.repository_root,
		reportFiles: 'gitler.html', reportName: 'Gitler report', reportTitles: ''])
	if (ret == 1) {
		config.pr.setBuildStatus(config, 'FAILURE', 'Toll gate (Gitler)', 'Commit(s) does not meet coding standards', '${BUILD_URL}Gitler_report/gitler.html')
		currentBuild.currentResult == 'FAILURE'
		echo "Termiated due to Gitler assert" // For BFA
		error 'Termiated due to Gitler assert'
	} else {
		config.pr.setBuildStatus(config, 'SUCCESS', 'Toll gate (Gitler)', 'Pass', '')
	}
}

return this