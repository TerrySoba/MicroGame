pipeline {
    agent none
    stages {
        stage('Build') {
            agent {
                label 'mingw64'
            }

            steps {
                echo 'Building..'
                bat 'cmake -GNinja .'
                bat 'ninja'
                bat 'ninja install'
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
            }
        }
    }
}

