
There are five major browsers used on desktop today: Chrome, Internet Explorer, Firefox, Safari and Opera. 

On mobile, the main browsers are Android Browser, iPhone, Opera Mini and Opera Mobile, UC Browser, the Nokia S40/S60 browsers and Chrome–all of which, except for the Opera browsers, are based on WebKit

* Items to fetch and display : Images, Text, Javascript, CSS, Animation, Video
* Single page vs multiple page
* PWA : progressive web app
* Code splitting vs bundling
* Preload vs Defer
* NetworkInformation API
* HTTP caching

## RAIL performance model:
1. Response : respond in 100 ms
1. Animation : produce frame in under 10 ms of scroll
1. Idle,  : maximize main thread idle time
1. Load. : interactive in under 5 sec

https://developers.google.com/web/fundamentals/performance/rail

## PRPL : 
1. push, 
1. render, 
1. precache, 
1. lazy load 

https://web.dev/apply-instant-loading-with-prpl/

https://developers.google.com/web/updates/2018/09/inside-browser-part3
https://developers.google.com/web/updates/2018/09/inside-browser-part4

Chrome gives each site its own process when it runs out of resources; otherwise each tab got a process

Multiple processes used for security, sandbox, unresponsive tabs

Site isolation : there can be multiple iframes in a tab.   Now each cross-site iframe within a tab gets a separate renderer process

## Browser process 

handles top of window.   It has UI thread, network thread, storage thread.

Lifecycle of URL typed in browser :
1. UI thread parses URL, sends request to backend
1. Response may be sent to network thread for further downloading (CSS, images)
1. Then response is sent to renderer thread
1. Update the address bar, session history
1. Renderer thread sends response back to UI thread
1. Client side javascript may keep loading

Another URL typed
1. Before navigating to a different site, check “beforeunload” event
1. Then new renderer process is invoked for the other site, while current renderer process handles current site

Page Lifecycle API
1. pages have states : active, passive, hidden, frozen, terminated, discarded
1. browser events : can freeze a page
1. user events : load, unload, visibility change
1. PageLifeCycle.js normalizes states across browsers

Page Navigation Cache
1. caches page in case user comes back after pressing forward or back button

Task Queues

WebSocket

WebRTC

Web Workers

https://developer.mozilla.org/en-US/docs/Web/API/Web_Workers_API/Using_web_workers

1. SharedWorker
1. EmbeddedWorker
1. ServiceWorker : act as proxy between browser and network
1. Navigator :

https://developer.mozilla.org/en-US/docs/Web/API/Navigator

## Renderer Process

handles drawing in tab

1. Main Thread, 
1. Compositor  thread, 
1. Raster thread

Main thread : 
1. converts HTML to DOM; when it finds “<script>”, it pauses and executes Javascript because Javascript can change document structure.  If you know it will not change doc structure, use async or defer tags.  For prefetch, use preload tag
1. then parse CSS to create Style information
1. From Style info, the Layout Tree is created with x, y coordinates
1. Then create Paint records to decide what to draw first 

For smooth animation, use “requestAnimationFrame”

How to draw the page after deciding Paint order ?  its called Rasterizing; has to be optimized for scrolling

1. Main thread : convert Layout Tree to Layer Tree
1. Compositor Thread : convert each layer into tiles.  A layer can have multiple tilings for different resolutions to handle things like zoom-in action.
1. Raster Thread : rasterize each tile and store them in GPU memory
1. Compositor Thread : Tiles gathered into compositor frame which is sent to browser process via IPC.  These compositor frames are sent to the GPU to display it on a screen

user event processing : browser process sends to renderer process

Renderer process (composite thread) finds event target and calls event listener

Non-fast scrollable region  : A region whose input event has to be sent to Main thread running in Renderer

Hit test : what is drawn at x,y point

Coalesced events

CSS is a render blocking resource
https://developers.google.com/web/fundamentals/performance/critical-rendering-path/render-blocking-css

page without CSS = "Flash of Unstyled Content" (FOUC).

Application shell keeps static assets in local cache - using ServiceWorker
https://developers.google.com/web/fundamentals/architecture/app-shell

separate content from navigation

## Javascript engine 

it is mix of interpreter and just-in-time compiler
https://mathiasbynens.be/notes/shapes-ics

All objects are dictionaries with variable : property attribute pairs

```
Object.getOwnPropertyDescriptor(object, 'foo');
```

Array is also similarly defined

### Problem : Property access needs to be optimized

Multiple objects with same keys have same “shape”

Javascript engine stores “Shape” separately from JSObject

All JavaScript engines use shapes as an optimization, but they don’t all call them shapes:

1. Academic papers call them Hidden Classes (confusing w.r.t. JavaScript classes)
1. V8 calls them Maps (confusing w.r.t. JavaScript Maps)
1. Chakra calls them Types (confusing w.r.t. JavaScript’s dynamic types and typeof)
1. JavaScriptCore calls them Structures
1. SpiderMonkey calls them Shapes

When you add a attribute to object, the Shapes form a transitive Chain

To speed up searching for an attribute, a ShapeTable is introduced (which is dictionary)

Shapes help in Inline Caching

The main motivation behind shapes is the concept of Inline Caches or ICs. ICs are the key ingredient to making JavaScript run fast! JavaScript engines use ICs to memorize information on where to find properties on objects, to reduce the number of expensive lookups.

For subsequent runs, the IC only needs to compare the shape, and if it’s the same as before, just load the value from the memorized offset.


# TODO

Understanding the V8 Javascript engine
https://www.youtube.com/watch?v=xckH5s3UuX4
