from flask import Flask,render_template, request
import zmq

app = Flask(__name__)


context = zmq.Context()
#  Socket to talk to server
print("Connecting to hello world server…")
socket = context.socket(zmq.REQ)
socket.connect("tcp://localhost:5555")



@app.route('/', methods=['GET', 'POST'])
def index():
  if request.method == 'POST':
    print("Sending message to console..")
    socket.send_string("close")

    #  Get the reply.
    message = socket.recv()
    print("Received reply [ %s ]" % message)

  return render_template('index.html')




if __name__ == "__main__":
  app.run(debug=True)