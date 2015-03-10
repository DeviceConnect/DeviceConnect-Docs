* 日本語説明はこちら
https://github.com/DeviceConnect/DeviceConnect-Docs/blob/master/readme.ja.md

# About DeviceConnect WebAPI
"DeviceConnect WebAPI" is WebAPI which operates as a virtual server on a smart phone. It can use easily various wearable devices and an IoT device by unific description from a web browser or an application. 

# Introduction
Device Connect system is a multi-OS, on the run-time environment of multi-platform, provides API (RESTful) for connection to a smart device.<br>
Thus, it is intended to improve the convenience of the connection and cooperation method between the smart device.<br>
<br> Function list Device Connect system provides is as follows.

- Provides the ability to display the peripheral list of possible cooperation
- Connection I / F eliminate (Bluetooth, BLE, Wi-Fi, NFC) a descriptive difficulty of the difference of
- Provide unified API by equipment profile



<a href="https://raw.githubusercontent.com/wiki/DeviceConnect/DeviceConnect-Android/DevicePluginManual/image1_en.png" style="text-align:center" ">
<img src="https://raw.githubusercontent.com/wiki/DeviceConnect/DeviceConnect-Android/DevicePluginManual/image1_en.png" border="0"
 width="251" height="235" alt="" style="text-align:center"/></a>

# Connecting to Device Connect

In Android version Device Connect, and that make an inquiry to the HTTP server (DeviceConnectManager) you are running in the local in the terminal, it is possible to perform hardware operations and, the information acquisition.

<a href="https://raw.githubusercontent.com/wiki/DeviceConnect/DeviceConnect-Android/DeviceConnectApplicationManual/image1.png" >
<img src="https://raw.githubusercontent.com/wiki/DeviceConnect/DeviceConnect-Android/DeviceConnectApplicationManual/image1.png" border="0"
 width="808" height="290" alt="" /></a><br>

# Repository of DeviceConnect

* [DeviceConnect-Android](http://github/DeviceConnect-Android)<br>
It is a repository that sample implement DeviceConnect platform on Android.<br>
In Android terminal, if you want to operate the DeviceConnect, please check out from this repository.<br>
<br>
* [DeviceConnect-iOS](http://github/DeviceConnect-iOS)<br>
It is a repository that sample implement DeviceConnect platform on iOS.<br>
In iOS terminal, if you want to operate the DeviceConnect, please check out from this repository.<br>
<br>
* [DeviceConnect-JS](http://github/DeviceConnect-JS)
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
           └── dConnect
                └── demoWebSite
```

2.Access the internal file URI with Chrome browser.
```
  file:///sdcard/dConnect/demoWebSite/index.html
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
 e.g. "file:///C:/demoWebSite/demo/index.html?ip=192.168.13.3"
 ```



#Supported devices
<table>
  <tr>
    <td>Manufacturer</td>
    <td>Product name</td>
    <td>Device type</td>
    <td>Plug-in</td>
    <td>Remarks</td>
  </tr>
  <tr>
    <td>SONY</td>
    <td>SmartWatchMN2</td>
    <td>Watch</td>
    <td>MN2/SW2</td>
    <td>Need the app launch on SmartWatch</td>
  </tr>
  <tr>
    <td>SONY</td>
    <td>SmartWatchSW2</td>
    <td>Watch</td>
    <td>MN2/SW2</td>
    <td>Need the app launch on SmartWatch</td>
  </tr>
  <tr>
    <td>Orbotix</td>
    <td>Sphero 2.0</td>
    <td>Toy</td>
    <td>Sphero</td>
    <td></td>
  </tr>
  <tr>
    <td>Game Technologies</td>
    <td>DICE+</td>
    <td>Toy</td>
    <td>DICE+</td>
    <td>Need the firmware for development</td>
  </tr>
  <tr>
    <td>Philips</td>
    <td>hue</td>
    <td>Light</td>
    <td>hue</td>
    <td></td>
  </tr>
  <tr>
    <td>Philips</td>
    <td>Bloom Lamp</td>
    <td>Light</td>
    <td>hue</td>
    <td></td>
  </tr>
  <tr>
    <td>Philips</td>
    <td>LightStrips</td>
    <td>Light</td>
    <td>hue</td>
    <td></td>
  </tr>
  <tr>
    <td>IRKit</td>
    <td>IRKit</td>
    <td>Infrared remote control</td>
    <td>IRKit</td>
    <td></td>
  </tr>
  <tr>
    <td>Epson</td>
    <td>Moverio BT-200</td>
    <td>Glasses</td>
    <td>Android Host</td>
    <td>The future works; Support the extension</td>
  </tr>
  <tr>
    <td>Vuzix</td>
    <td>M100 Smart Glass</td>
    <td>Glasses</td>
    <td>Android Host</td>
    <td>The future works; Support the extension</td>
  </tr>
  <tr>
    <td>WESTUNITIS</td>
    <td>Inforod</td>
    <td>Glasses</td>
    <td>Android Host</td>
    <td>The future works; Support the extension</td>
  </tr>
  <tr>
    <td>SONY</td>
    <td>DSC-QX100</td>
    <td>Camera</td>
    <td>SonyCamera</td>
    <td></td>
  </tr>
  <tr>
    <td>SONY</td>
    <td>DSC-QX10</td>
    <td>Camera</td>
    <td>SonyCamera</td>
    <td></td>
  </tr>
  <tr>
    <td>Pebble</td>
    <td>Pebble</td>
    <td>Watch</td>
    <td>Pebble</td>
    <td></td>
  </tr>
  <tr>
    <td>-</td>
    <td>Android Ver4.0</td>
    <td>Android</td>
    <td>Android Host</td>
    <td></td>
  </tr>
  <tr>
    <td>LG</td>
    <td>G Watch</td>
    <td>Android  Wear</td>
    <td>Wear</td>
    <td>Provisional support</td>
  </tr>
  <tr>
    <td>Samsung</td>
    <td>Gear Live</td>
    <td>Android  Wear</td>
    <td>Wear</td>
    <td>Provisional support</td>
  </tr>
  <tr>
    <td>Google</td>
    <td>ChromeCast</td>
    <td>ChromeCast</td>
    <td>Chromecast</td>
    <td>Need to register the Receiver Apps and device on Google Cast SDK Developer Console.</td>
  </tr>
  <tr>
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
  <tr>
    <td>Polar</td>
    <td>H7</td>
    <td>Heart rate meter</td>
    <td>mHealth</td>
    <td></td>
  </tr>
  <tr>
    <td>Mio Global</td>
    <td>Mio Alpha</td>
    <td>Heart rate meter</td>
    <td>mHealth</td>
    <td></td>
  </tr>
</table>
