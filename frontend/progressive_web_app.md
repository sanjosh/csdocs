
```
User visits your site

Browser downloads and installs the service worker

Manifest prompts user to install the app (add to home screen)

On repeat visits, service worker serves cached content (very fast)

User can interact with the app even offline
```

# building blocks

## Service Worker

A background script that:

Caches files for offline use

Intercepts network requests

Handles background sync and push notifications

## Web App Manifest (manifest.json)

Metadata that defines:

App name, icons, theme colors

Start URL and display mode (e.g., full screen)

Install prompts

## HTTPS

Required for service workers and push notifications.
