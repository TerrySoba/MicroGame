pipeline {
    agent none

    options {
        skipDefaultCheckout()
    }

    stages {
        stage('Build') {
            agent {
                label 'vs2017'
            }

            steps {
                checkout scm
                echo 'Building..'
                bat 'C:\\env.bat && cmake -GNinja -DCMAKE_BUILD_TYPE=Release .'
                bat 'C:\\env.bat && ninja'
                bat 'C:\\env.bat && ninja install'

                stash includes: 'install/**', name: 'installed_app'

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
                unstash 'installed_app'
                bat 'install\\MicroGame\\bin\\MicroGame.exe --version'
            }
        }
    }
}

