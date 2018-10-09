pipeline {
    agent {
	label 'mingw64'
    }

    stages {
        stage('Build') {
            steps {
                echo 'Building..'
                bat 'cmake -GNinja .'
                bat 'ninja'
                bat 'ninja install'
                bat 'ninja zip'
                archiveArtifacts artifacts: '**/*.zip', fingerprint: true
            }
        }
    }
}

