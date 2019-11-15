$(document).ready(function(){

        
        (function poll(){
          $.ajax({
            url: "/poll",
            success: function (data) {
              console.log("polling!");
            },
            dataType: "json",
            complete: poll,
            timeout: 30000
          });
        })();

});