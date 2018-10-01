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
            }
        }
        stage('Test') {
            steps {
                echo 'Testing..'
            }
        }
        stage('Deploy') {
            steps {
                echo 'Deploying....'
            }
        }
    }
}

