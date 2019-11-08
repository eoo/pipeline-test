# pipeline-test
Skeletop app - to deliver a message from web browser to console application


## Setting up environment and application:

  1. ### Install Python 3 and pip
          
          sudo yum install python3
          
  2. ### Clone this repo
          
          git clone https://github.com/eoo/pipeline-test.git
          cd pipeline-test
          
  3. ### Install required packages
          
          pip3 install -r requirements.txt
          
  4. ### Compile C Program
          
          cd console
          gcc -o zmqserver console.c -lpthread -lzmq
          
          
 
## Running the pipeline

  1. Open console and run ZMQ Server using
          
          cd console
          ./zmqserver
          
  2. Run Flask WebServer
          
          export FLASK_APP='app.py'
          flask run
          
  3. Open Web Browser and goto
          http://127.0.0.1:5000/
          


### Supported Commands : close
   
