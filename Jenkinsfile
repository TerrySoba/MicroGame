pipeline {
    agent none

    options {
        skipDefaultCheckout()
    }

    stages {
        stage('Build') {
            agent {
                label 'mingw64'
            }

            steps {
                checkout scm
                echo 'Building..'
                bat 'cmake -GNinja .'
                bat 'ninja'
                bat 'ninja install'

                stash includes: 'install', name: 'app'

                bat 'ninja zip'
                archiveArtifacts artifacts: '**/*.zip', fingerprint: true
            }
        }

        stage('Smoke Test') {
            agent {
                label 'windows'
            }

            steps {
                echo 'Running Smoke Test'
                unstash 'app'
            }
        }
    }
}

