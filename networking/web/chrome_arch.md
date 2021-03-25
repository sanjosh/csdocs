
# Chrome architecture

## Goals

1. stable
rendering should not hang the UI
comm is async to ensure UI is not janky
separate address spaces

2. fast : exploit multi-core

3. secure: limit harm by separating renderer

## Processes

To kill a tab, just close process if it does not have unload handlers

### Renderer process (renders pixels)
WebView
RenderView one for each tab
WebView in WebKit

### Browser process (one for each tab) 

process RenderProcessHost
RenderViewHost runs in Browser
Like hWnd in Windows

## IPC
Not COM - not fully async
Should be Non blocking from browser side
Named Pipes

## Threads 

### Threads in Chrome Browser

1. UI thread - purely async
2. IO thread - IPC
3. Network loading
4. Routing thread
5. File thread - blocking IO, COM, SHell32
6. DB thread - sqlite

### Threads in RenderProcess 

1. IO thread - IPC
2. Render thread = webkit main thread (webkit was single threaded lib)

## Deadlocks

Plugins can cause deadlocks when doing synchronous IPC
UI thread -> parent hWnd -> child hWind for Flash -> Webkit execute script -> waits UI Thread
because there is Synchronous IPC between parent and child hWnd
which can send synchronous IPC to Webkit to execute script
which may be talking synchronous to UI thread

*Rule* : any sync IPC from Renderer should not terminate in UI thread

Detect and kill unresponsive plugins

## How is rendering done

what do these problems have in common
1. painting
2. Scrolling
3. Resizing (size changed - paint - ipc to webkit - wait)
4. restoring tabs

InputEvent goes to Webkit
Webkit sends back Rect
RenderViewHost sends back Ack

Every RenderViewHost(browser) has a backing store
pixels come from RenderView which can update backing store async

## Memory

Backing store uses lot of Mem; each tab has one
Backing store is dropped if tab is inactive
Then you produce pixels from Webkit

# References

1. Darin Fisher  https://www.youtube.com/watch?v=A0Z0ybTCHKs
