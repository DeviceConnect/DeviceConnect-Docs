* 日本語説明はこちら
https://github.com/DeviceConnect/DeviceConnect-Docs/blob/master/readme.ja.md

# About DeviceConnect WebAPI
"DeviceConnect WebAPI" is WebAPI which operates as a virtual server on a smart phone. It can use easily various wearable devices and an IoT device by unific description from a web browser or an application.

# Introduction
Device Connect system is a multi-OS, on the run-time environment of multi-platform, provides API (RESTful) for connection to a smart device.<br>
Thus, it is intended to improve the convenience of the connection and cooperation method between the smart device.<br>
<br> Function list Device Connect system provides is as follows.

- Service discovery
- Connection I/F eliminate (Bluetooth, BLE, Wi-Fi, NFC) a descriptive difficulty of the difference of
- Uniform API provided by equipment profiles
- Application authorization by users


<a href="https://raw.githubusercontent.com/wiki/DeviceConnect/DeviceConnect-Android/DevicePluginManual/studio1_en.png" style="text-align:center" ">
<img src="https://raw.githubusercontent.com/wiki/DeviceConnect/DeviceConnect-Android/DevicePluginManual/studio1_en.png" border="0"
 width="251" height="235" alt="" style="text-align:center"/></a>

# Security
Device Connect system implements the security features that are defined in OMA GotAPI v1.0.
 
## Application approval feature
It is the feature to block accesses from applications which are not authorized by user.
 
When a Device Connect application accesses the Device Connect system for the first time, the application should get an access token with user’s authorization. If the application tries to access the device without access token, the Device Connect system will return error to the application.
 
In addition, this feature can be turned OFF on the setting window of Device Connect Manager.
 
## Server spoofing detection
NOTE: This feature is currently supported by only Android version.
It is the feature to allow the application to detect whether Device Connect system is spoofed by other applications or not.
 
The following is summary of the sequence of this feature.
First, the application requests the Device Connect system to set a signature to response message. The request should be sent as URL scheme. In addition, the request contains a string which is key to generate signature of response message.
 
If the response message does not have a valid signature the application subsequently received, the application judges that the response message should not be sent from genuine Device Connect system.
 
Please refer the specifications of the OMA GotAPI v1.0 for details of sequence.
 
## Access restrictions
It is the feature to prohibit accesses from applications which are not included in the white list.
 
If this feature is turned ON, the Device Connect system checks Origin header of the request message received from the application. If 'Origin' is not included in the white list, the Device Connect system will return error to the application.
 
User can configure to accept accesses from the specific Origins in the settings of Device Connect Manager.
 
In addition, this feature can be turned OFF on the setting window of Device Connect Manager.
 
#Application Requirements
## Application must specify the origin of requests
In accordance with OMA GotAPI v1.0, the access from a Device Connect application is authorized by the Device Connect system only if the application itself is the Origin of the HTTP request. The Device Connect system returns error response for HTTP request without specified Origin. Device Connect applications should specify its Origin when HTTP request.

### For HTML Applications
HTML application must specify `Origin` header defined by [RFC6454](https://www.ietf.org/rfc/rfc6454.txt) in HTTP request header.

Example:

```
GET /gotapi/availability HTTP/1.1
Host: 127.0.0.1:4035
Origin: http://xxx.example.com/
```

The `Origin` header is specified automatically by Chrome, Safari and Firefox browsers, except for cases that GET request is sent from the address bar.

### For OS-native Applications
OS-native application must specify the identifier of the application (its package name) in `X-GotAPI-Origin` header.

Example:

```
GET /gotapi/availability HTTP/1.1
Host: 127.0.0.1:4035
X-GotAPI-Origin: com.example.android.app
```

# Connecting to Device Connect

The basic sequence of Device Connect is shown below.

<a href="./assets/sequence_overview.png" >
<img src="./assets/sequence_overview.png" border="0"
 width="100%" alt="" /></a><br>

# Repository of DeviceConnect

* [DeviceConnect-Android](http://github/DeviceConnect-Android)<br>
It is a repository that sample implement DeviceConnect platform on Android.<br>
In Android terminal, if you want to operate the DeviceConnect, please check out from this repository.<br>
<br>
* [DeviceConnect-iOS](http://github/DeviceConnect-iOS)<br>
It is a repository that sample implement DeviceConnect platform on iOS.<br>
In iOS terminal, if you want to operate the DeviceConnect, please check out from this repository.<br>
<br>
* [DeviceConnect-JS](http://github/DeviceConnect-JS)<br>
It is a repository that implements the SDK for calling DeviceConnect from HTML.

# Example for Android
* https://github.com/DeviceConnect/DeviceConnect-Docs/blob/master/Bin/demoWebSite.zip

_Updated some package names of the sample for Android at 2014/10/15._
_Please reinstall by following procedure if you would check this sample again._

```
  1. Delete files that are related to the demoWebSite.zip on internal storage.
  2. Uninstall a APK of old Manager and plugins.
  3. Choose "CLEAR BROWSING DATA..." in "history" on Chrome Browser menu.
  4. Choose "Clear" button with "Clear the cache" check box.
  5. Refer to the procedure for "Example for Android" in "Readme.md".
```

1.Make this Folder to Android's internal Storage.
```
Android root
   └── mnt
       └── sdcard
           └── demoWebSite
```

2.Access the internal file URI with Firefox browser.
```
  [例] file:///sdcard/demoWebSite/index.html
```

3.Install the Manager APK and the Android Host APK from "Download APK".
  If you have other supported gadgets , install other APKs.

4.Go back to the top page.

5.Try the prototype GotAPI behavior from "Launch UI-App".

##About access from the external devices

By adding the parameter of the IP address to the demoWebSite URL, can control the external device  by DeviceConnect WebAPI  at a local network. However, the following settings are required for terminal on the operation side.

_*Please do not use at network that can not be trusted because there is a security risk._

1. By the procedure as above , set up the DeviceConnect WebAPI to the terminal of the operation target.

2. Start the DeviceConnectManager from the launcher of Android,and turn off the slide toggle for DeviceConnectManager  service.
3. Enable "Allow External IP" checkbox, and turn on the slide toggle for DeviceConnectManager  service.

4. Add the IP address of the operation target in URL of demoWebSite on the operation side terminal.
```
 e.g. file:///C:/demoWebSite/demo/index.html?ip=192.168.13.3#demo
 ```

#Supported devices
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
    <td>MN2/SW2</td>
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
    <td>Light</td>
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
    <td>Android Host</td>
    <td>○</td>
    <td>×</td>
    <td>The future works; Support the extension</td>
  </tr>
  <tr>
    <td>Vuzix</td>
    <td>M100 Smart Glass</td>
    <td>Glasses</td>
    <td>Android Host</td>
    <td>○</td>
    <td>×</td>
    <td>The future works; Support the extension</td>
  </tr>
  <tr>
    <td>WESTUNITIS</td>
    <td>Inforod</td>
    <td>Glasses</td>
    <td>Android Host</td>
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
    <td>Android Ver4.0</td>
    <td>Android</td>
    <td>Android Host</td>
    <td>○</td>
    <td>×</td>
    <td></td>
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
    <td>Chromecast</td>
    <td>○</td>
    <td>○</td>
    <td>Need to register the Receiver Apps and device on Google Cast SDK Developer Console.</td>
  </tr>

<!--  <tr>
    <td>AND</td>
    <td>UA-767PBT-C</td>
    <td>Sphygmomanometer</td>
    <td>mHealth</td>
    <td></td>
  </tr>
  <tr>
    <td>AND</td>
    <td>UA-851PBT-C</td>
    <td>Sphygmomanometer</td>
    <td>mHealth</td>
    <td></td>
  </tr>
  <tr>
    <td>AND</td>
    <td>TM-2656VPM</td>
    <td>Sphygmomanometer</td>
    <td>mHealth</td>
    <td></td>
  </tr>
  <tr>
    <td>AND</td>
    <td>UC-321PBT-C</td>
    <td>Weight scale</td>
    <td>mHealth</td>
    <td></td>
  </tr>
  <tr>
    <td>OMRON HEALTHCARE</td>
    <td>HBF-206IT</td>
    <td>Body composition monitors</td>
    <td>mHealth</td>
    <td></td>
  </tr>
  <tr>
    <td>OMRON HEALTHCARE</td>
    <td>HHX-IT1</td>
    <td>Activity meter</td>
    <td>mHealth</td>
    <td></td>
  </tr>
  <tr>
    <td>AND</td>
    <td>UA-772</td>
    <td>Sphygmomanometer</td>
    <td>mHealth</td>
    <td></td>
  </tr>
  <tr>
    <td>AND</td>
    <td>UW201</td>
    <td>Activity meter</td>
    <td>mHealth</td>
    <td></td>
  </tr>
  <tr>
    <td>OMRON HEALTHCARE</td>
    <td>HEM-7250IT</td>
    <td>Sphygmomanometer</td>
    <td>mHealth</td>
    <td>In preparation</td>
  </tr>
  <tr>
    <td>OMRON HEALTHCARE</td>
    <td>HBF-208IT</td>
    <td>Body composition monitors</td>
    <td>mHealth</td>
    <td>In preparation</td>
  </tr>
  <tr>
    <td>OMRON HEALTHCARE</td>
    <td>HBF-215IT</td>
    <td>Body composition monitors</td>
    <td>mHealth</td>
    <td>In preparation</td>
  </tr>
  <tr>
    <td>ESTERA</td>
    <td>FS-500</td>
    <td>Pedometer</td>
    <td>mHealth</td>
    <td></td>
  </tr>
  <tr>
    <td>ESTERA</td>
    <td>FS-700</td>
    <td>Activity meter</td>
    <td>mHealth</td>
    <td></td>
  </tr>
  <tr>
    <td>YAMASA</td>
    <td>EX-950</td>
    <td>Pedometer</td>
    <td>mHealth</td>
    <td></td>
  </tr>
  <tr>
    <td>TERUMO</td>
    <td>MS-FRV01</td>
    <td>Blood glucose meter</td>
    <td>mHealth</td>
    <td>In preparation</td>
  </tr>
  <tr>
    <td>TERUMO</td>
    <td>MT-KT02DZ</td>
    <td>Walking intensity meter</td>
    <td>mHealth</td>
    <td>In preparation</td>
  </tr>
  <tr>
    <td>TERUMO</td>
    <td>C215</td>
    <td>Thermometer</td>
    <td>mHealth</td>
    <td>In preparation</td>
  </tr>
  <tr>
    <td>TERUMO</td>
    <td>ES-H700D</td>
    <td>Sphygmomanometer</td>
    <td>mHealth</td>
    <td>In preparation</td>
  </tr>
  <tr>
    <td>TERUMO</td>
    <td>ZS-NS05</td>
    <td>Pulse Oximeter</td>
    <td>mHealth</td>
    <td>In preparation</td>
  </tr>
  <tr>
    <td>TERUMO</td>
    <td>WT-B100DZ</td>
    <td>Body composition monitors</td>
    <td>mHealth</td>
    <td>In preparation</td>
  </tr>
-->  <tr>
    <td>Polar</td>
    <td>H7</td>
    <td>Heart rate meter</td>
    <td>BLE Heart Rate</td>
    <td>○</td>
    <td>×</td>
    <td></td>
  </tr>
  <tr>
    <td>Mio Global</td>
    <td>Mio Alpha</td>
    <td>Heart rate meter</td>
    <td>BLE Heart Rate</td>
    <td>○</td>
    <td>×</td>
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
    <td>FUJITSU</td>
    <td>F-PLUG</td>
    <td>Smart Meter</td>
    <td>F-PLUG</td>
    <td>○</td>
    <td>×</td>
    <td></td>
  </tr>
  <tr>
    <td>RICOH</td>
    <td>THETA m15</td>
    <td>Spherical Camera</td>
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
    <td>White 800 can not change color.</td>
  </tr>
</table>

* This project is not a formal service provision as NTT docomo. It is an experimental source code disclosure. The purpose is consideration of specifications and security.
* Each manufacturer does not guarantee the operation.
* Available functions vary with each device.
* The source code of the plug-in will be disclosed about some equipment by convenience of development for the library to be used.
* We will advance sequentially that updating documents and expanding enabled devices.
* Specifications may be changed by improvement of security or other reasons.
