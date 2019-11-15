from flask import Flask,render_template, request, json
import zmq
import time

app = Flask(__name__)


context = zmq.Context()
#  Socket to talk to server
print("Connecting to ZMQ server…")
socket = context.socket(zmq.REQ)
socket.connect("tcp://localhost:5555")



@app.route('/', methods=['GET', 'POST'])
def index():
  if request.method == 'POST':
    command = request.json['command']
    print(request.json)
    print("Got message from client to : ", command)
    
    print("Sending message to console..")
    socket.send_string(command)

    #  Get the reply.
    message = socket.recv()
    print("Received reply [ %s ]" % message)


  return render_template('index.html')


@app.route('/poll', methods=['GET'])
def poll():
  time.sleep(1)
  return "pollinggg"


if __name__ == "__main__":
  app.run(debug=True)