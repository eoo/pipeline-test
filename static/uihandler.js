$(document).ready(function(){

    $(".controlpanel button").click(function(){

          var buttonid = $(this).attr('id');
          console.log('button id = ' , buttonid);


          var message;
          if (buttonid == 'printButton') message = 'print';
          if (buttonid == 'closeButton') message = 'close';

          console.log('sending message to server : ', message);

          $.ajax({
            type : "POST",
            url : '{{url_for('/')}}',
            success : function (data) {
                        alert("Success!");
                    },
            contentType: 'application/json',
            dataType: "json",
            data: JSON.stringify({command: message}),            
          });

    });

});