#define SECRET_SSID "IPUP"
#define SECRET_PASSWORD "HansOgPeter2300"

const char webPageCode[] =
R"=====(

<!DOCTYPE HTML>

<html>
<!---------------------------------- CSS ---------------------------------->

<head>
    <title>ESP8266 WebServer Running Lights</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
 <style>
     body { font-family: Arial; text-align: center; margin:0px auto; padding-top: 30px;}
      .button {
        padding: 20px 30px;
        font-size: 24px;
        text-align: center;
        outline: none;
        color: #fff;
        background-color: #2f4468;
        border: none;
        border-radius: 5px;
        box-shadow: 0 6px #999;
        cursor: pointer;
        -webkit-touch-callout: none;
        -webkit-user-select: none;
        -khtml-user-select: none;
        -moz-user-select: none;
        -ms-user-select: none;
        user-select: none;
        -webkit-tap-highlight-color: rgba(0,0,0,0);
      }  
      .button:hover {background-color: #1f2e45}
      .button:active {
        background-color: #1f2e45;
        box-shadow: 0 4px #666;
        transform: translateY(2px);
      }
  </style>
</head>

<!---------------------------------- HTML ---------------------------------->

<body>
  <h1>ESP Pushbutton RobotArm Web Server</h1>
    <button class="button" onmousedown="toggleCheckbox('runningLights');" ontouchstart="toggleCheckbox('runningLights');" onmouseup="toggleCheckbox('stop');" ontouchend="toggleCheckbox('stop');">Execute Running lights</button>
    


<!---------------------------------- JavaScript ---------------------------------->

<script>

  function toggleCheckbox(x) {
     var xhr = new XMLHttpRequest();
     xhr.open("GET", "/" + x, true);
     xhr.send();
   }
</script>
</body>
</html>
)=====";
