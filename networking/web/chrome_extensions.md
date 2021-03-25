

# Extension API

https://developer.chrome.com/extensions/api_index

## extension manifest

manifest file is json and has
1. permissions
1. icons
1. other

```
"name" :
"permissions" : []
"background"
```

## alarms

## bookmarks

## certificateProvider

## events

declarative event handlers

## identity 

OAuth2 

## fileBrowserHandler

## fileSystemProvider

virtual file systems

Use cases include decompressing archives and accessing files in a cloud service other than Drive. 

## login state


## proxy



## vpnprovider

## webrequest

extension can modify request headers

https://developer.chrome.com/extensions/webRequest

## ttsEngine 

https://developer.chrome.com/extensions/ttsEngine

Extensions are free to use any available web technology to provide speech, including streaming audio from a server, HTML5 audio, Native Client, or Flash.

https://chromium.googlesource.com/chromium/src/+/master/chrome/common/extensions/docs/examples/api/ttsEngine/console_tts_engine/console_tts_engine.js


https://github.com/ashwanthkumar/chrome-tts-tamizh

```
 $.post(TTS_SERVER, {"gender" : gender, "text": utterance}, function(response) {
    console.debug(response);
    speakFromAudio(response.url, utterance, sendTtsEvent);
  });

function speakFromAudio(url, utterance, sendTtsEvent) {
  console.debug("Started speaking");
  console.debug("I'm speaking - " + utterance);

  sendTtsEvent({'type': 'start', 'charIndex': 0});
  audio = new Audio();
  audio.src = url;
  audio.addEventListener('ended', function() {
    sendTtsEvent({'type': 'end', 'charIndex': utterance.length});
    console.debug("Finished speaking");
  });
  audio.play();
}
```

