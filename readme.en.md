* 日本語説明は[こちら](README.md)

# About DeviceConnect System
Device Connect system is a Web API that run as a virtual server on a smartphone, and easy to use the wearable device and IoT device from Browser or application.

Click [here](https://github.com/DeviceConnect/DeviceConnect-Docs/wiki)
 about DeviceConnect System. 

# Repository of DeviceConnect

* [DeviceConnect-Spec](https://github.com/DeviceConnect/DeviceConnect-Spec)<br>
It is a repository that manages the specification of DeviceConnect API for each profile.<br>
It is defined based on Swagger 2.0.

* [DeviceConnect-Android](https://github.com/DeviceConnect/DeviceConnect-Android)<br>
It is a repository that sample implement DeviceConnect platform on Android.<br>
In Android terminal, if you want to operate the DeviceConnect, please check out from this repository.

* [DeviceConnect-iOS](https://github.com/DeviceConnect/DeviceConnect-iOS)<br>
It is a repository that sample implement DeviceConnect platform on iOS.<br>
In iOS terminal, if you want to operate the DeviceConnect, please check out from this repository.

* [DeviceConnect-JS](https://github.com/DeviceConnect/DeviceConnect-JS)<br>
It is a repository that implements the SDK for calling DeviceConnect from HTML.

* [DeviceConnect-Common](https://github.com/DeviceConnect/DeviceConnect-Common)<br>
DeviceConnect-Android, and a repository of applications that run on devices that work with DeviceConnect-iOS.

* [DeviceConnect-NodeJS](https://github.com/DeviceConnect/DeviceConnect-NodeJS)<br>
It is a repository that implements DeviceConnect platform on RaspberryPi.<br>

* [DeviceConnect-PodSpecs](https://github.com/DeviceConnect/DeviceConnect-PodSpecs)<br>
It is a repository that manages configuration files for importing DeviceConnect-iOS libraries using CocoaPod.<br>

* [DeviceConnect-Experiments](https://github.com/DeviceConnect/DeviceConnect-Experiments)<br>
It is a repository that arranges experimental applications such as DeviceConnect.

# Supported Devices
<table>
 <tr>
    <td>Manufacturer</td>
    <td>Product name</td>
    <td>Device type</td>
    <td>Plug-in</td>
    <td>Android</td>
    <td>iOS</td>
    <td>Remarks</td>
  </tr>
   <tr>
    <td>SONY</td>
    <td>SmartWatchMN2</td>
    <td>Watch</td>
    <td>MN2/SW2 </td>
    <td>○</td>
    <td>×</td>
    <td>Need the app launch on SmartWatch</td>
  </tr>
  <tr>
    <td>SONY</td>
    <td>SmartWatchSW2</td>
    <td>Watch</td>
    <td>MN2/SW2</td>
    <td>○</td>
    <td>×</td>
    <td>Need the app launch on SmartWatch</td>
  </tr>
  <tr>
    <td>Orbotix</td>
    <td>Sphero 2.0</td>
    <td>Toy</td>
    <td>Sphero</td>
    <td>○</td>
    <td>○</td>
    <td></td>
  </tr>
  <tr>
    <td>Game Technologies</td>
    <td>DICE+</td>
    <td>Toy</td>
    <td>DICE+</td>
    <td>○</td>
    <td>○</td>
    <td>Need the firmware for development</td>
  </tr>
  <tr>
    <td>Philips</td>
    <td>hue</td>
    <td>Light</td>
    <td>hue</td>
    <td>○</td>
    <td>○</td>
    <td></td>
  </tr>
  <tr>
    <td>Philips</td>
    <td>Bloom Lamp</td>
    <td>スマートライト</td>
    <td>hue</td>
    <td>○</td>
    <td>○</td>
    <td></td>
  </tr>
  <tr>
    <td>Philips</td>
    <td>LightStrips</td>
    <td>Light</td>
    <td>hue</td>
    <td>○</td>
    <td>○</td>
    <td></td>
  </tr>
  <tr>
    <td>IRKit</td>
    <td>IRKit</td>
    <td>Infrared remote control</td>
    <td>IRKit</td>
    <td>○</td>
    <td>○</td>
    <td></td>
  </tr>
  <tr>
    <td>Epson</td>
    <td>Moverio BT-200</td>
    <td>Glasses</td>
    <td>AndroidHost</td>
    <td>○</td>
    <td>×</td>
    <td>The future works; Support the extension</td>
  </tr>
  <tr>
    <td>Vuzix</td>
    <td>M100 Smart Glass</td>
    <td>Glasses</td>
    <td>AndroidHost</td>
    <td>○</td>
    <td>×</td>
    <td>The future works; Support the extension</td>
  </tr>
  <tr>
    <td>WESTUNITIS</td>
    <td>Inforod</td>
    <td>Glasses</td>
    <td>AndroidHost</td>
    <td>○</td>
    <td>×</td>
    <td>The future works; Support the extension</td>
  </tr>
  <tr>
    <td>SONY</td>
    <td>DSC-QX100</td>
    <td>Camera</td>
    <td>SonyCamera</td>
    <td>○</td>
    <td>○</td>
    <td></td>
  </tr>
  <tr>
    <td>SONY</td>
    <td>DSC-QX10</td>
    <td>Camera</td>
    <td>SonyCamera</td>
    <td>○</td>
    <td>○</td>
    <td></td>
  </tr>
  <tr>
    <td>SONY</td>
    <td>ActionCam</td>
    <td>Camera</td>
    <td>SonyCamera</td>
    <td>○</td>
    <td>○</td>
    <td></td>
  </tr>
  <tr>
    <td>Pebble</td>
    <td>Pebble</td>
    <td>Watch</td>
    <td>Pebble</td>
    <td>○</td>
    <td>○</td>
    <td></td>
  </tr>
  <tr>
    <td>-</td>
    <td>Android  Ver4.2 or later</td>
    <td>Android</td>
    <td>AndroidHost</td>
    <td>○</td>
    <td>×</td>
    <td>Ver4.2 or later</td>
  </tr>
  <tr>
    <td>LG</td>
    <td>G Watch</td>
    <td>Android  Wear</td>
    <td>Wear</td>
    <td>○</td>
    <td>×</td>
    <td>Provisional support</td>
  </tr>
  <tr>
    <td>Samsung</td>
    <td>Gear Live</td>
    <td>Android  Wear</td>
    <td>Wear</td>
    <td>○</td>
    <td>×</td>
    <td>Provisional support</td>
  </tr>
  <tr>
    <td>Google</td>
    <td>ChromeCast</td>
    <td>ChromeCast</td>
    <td>ChromeCast</td>
    <td>○</td>
    <td>○</td>
    <td>Need to register the Receiver Apps and device on Google Cast SDK Developer Console.</td>
  </tr>
  <tr>
    <td>Google</td>
    <td>NexusPlayer</td>
    <td>AndroidTV</td>
    <td>ChromeCast</td>
    <td>○</td>
    <td>○</td>
    <td>Need to register the Receiver Apps and device on Google Cast SDK Developer Console.</td>
  </tr>

  <tr>
    <td>Polar</td>
    <td>H7</td>
    <td>Heart rate meter</td>
    <td>BLE HeartRate</td>
    <td>○</td>
    <td>×</td>
    <td></td>
  </tr>
  <tr>
    <td>Mio Global</td>
    <td>Mio Alpha</td>
    <td>Heart rate meter</td>
    <td>BLE HeartRate</td>
    <td>○</td>
    <td>×</td>
    <td></td>
  </tr>
  <tr>
    <td>Mio Global</td>
    <td>Mio Fuse</td>
    <td>Heart rate meter</td>
    <td>BLE HeartRate</td>
    <td>○</td>
    <td>×</td>
    <td></td>
  </tr>
    <tr>
    <td>EPSON</td>
    <td>Pulsense PS-500</td>
    <td>Heart rate meter</td>
    <td>BLE HeartRate</td>
    <td>○</td>
    <td>×</td>
    <td></td>
  </tr>
    <tr>
    <td>EPSON</td>
    <td>Pulsense PS-100</td>
    <td>Heart rate meter</td>
    <td>BLE HeartRate</td>
    <td>○</td>
    <td>×</td>
    <td></td>
  </tr>
  <tr>
    <td>NTT DOCOMO</td>
    <td>Hitoe</td>
    <td>Heart rate meter</td>
    <td>Hitoe</td>
    <td>○</td>
    <td>○</td>
    <td>Now under development</td>
  </tr>
  <tr>
    <td>A&D</td>
    <td>UT-201BLE</td>
    <td>Thermometer</td>
    <td></td>
    <td>○</td>
    <td>x</td>
    <td></td>
  </tr>
  <tr>
    <td>OMRON</td>
    <td>HVC-C</td>
    <td>Human Vision Components</td>
    <td>HVC</td>
    <td>○</td>
    <td>×</td>
    <td></td>
  </tr>
  <tr>
    <td>OMRON</td>
    <td>HVC-C2W</td>
    <td>Human Vision Components</td>
    <td>HVC2W</td>
    <td>○</td>
    <td>×</td>
    <td></td>
  </tr>
  <tr>
    <td>OMRON</td>
    <td>HVC-P</td>
    <td>Human Vision Components</td>
    <td>HVCP</td>
    <td>○</td>
    <td>×</td>
    <td></td>
  </tr>
  <tr>
    <td>FUJITSU</td>
    <td>F-PLUG</td>
    <td>SmartMeter</td>
    <td>F-PLUG</td>
    <td>○</td>
    <td>×</td>
    <td></td>
  </tr>
  <tr>
    <td>RICOH</td>
    <td>THETA m15</td>
    <td>Omnidirectional Camera</td>
    <td>THETA</td>
    <td>○</td>
    <td>○</td>
    <td>Need to register developer and download SDK at RICHO THETA Developers.</td>
  </tr>
    <tr>
    <td>RICOH</td>
    <td>THETA S</td>
    <td>Omnidirectional Camera</td>
    <td>THETA</td>
    <td>○</td>
    <td>○</td>
    <td>Need to register developer and download SDK at RICHO THETA Developers.</td>
  </tr>

  <tr>
    <td>LIFX</td>
    <td>White 800</td>
    <td>Light</td>
    <td>AllJoyn</td>
    <td>○</td>
    <td>○</td>
    <td>No color change.</td>
  </tr>
  <tr>
    <td>LIFX</td>
    <td>Color 1000</td>
    <td>Light</td>
    <td>AllJoyn</td>
    <td>○</td>
    <td>○</td>
    <td></td>
  </tr>
  <tr>
    <td>EchonetLite</td>
    <td>Standard-compliant equipment in general</td>
    <td>Home control</td>
    <td>EchoneLite</td>
    <td>○</td>
    <td>×</td>
    <td>Standard-compliant equipment in general</td>
  </tr>
  <tr>
    <td>Linking</td>
    <td>Tomoru</td>
    <td>BLE</td>
    <td>Linking</td>
    <td>○</td>
    <td>○</td>
    <td>Now under development</td>
  </tr>
  <tr>
    <td>－</td>
    <td>UVC(USB Video Class)</td>
    <td>USBCamera</td>
    <td>UVC</td>
    <td>○</td>
    <td>×</td>
    <td></td>
  </tr>
  <tr>
    <td>－</td>
    <td>Mobile camera</td>
    <td>TV conference,Remote work support</td>
    <td>WebRTC</td>
    <td>○</td>
    <td>×</td>
    <td></td>
  </tr>
  <tr>
    <td>Infinitegra</td>
    <td>OWLIFT</td>
    <td>Thermal camera</td>
    <td></td>
    <td>○</td>
    <td>×</td>
    <td></td>
  </tr>
  <tr>
    <td>FaBo</td>
    <td>FaBo</td>
    <td>IoT HW Prototype kit</td>
    <td>FaBo</td>
    <td>○</td>
    <td>×</td>
    <td></td>
  </tr>

</table>


* This project is not a formal service provision as NTT docomo. It is an experimental source code disclosure. The purpose is consideration of specifications and security.
* Each manufacturer does not guarantee the operation.
* Available functions vary with each device.
* The source code of the plug-in will be disclosed about some equipment by convenience of development for the library to be used.
* We will advance sequentially that updating documents and expanding enabled devices.
* Specifications may be changed by improvement of security or other reasons.
