
# playwright

https://www.checklyhq.com/docs/browser-checks/screenshots/

https://www.browserstack.com/guide/playwright-vs-selenium

Headless Browser with event-driven architecture

Timeout-free automation. 

Playwright receives browser signals, like network requests, page navigations and page load events to eliminate the need for sleep timeouts that cause flakiness.

## uses CDP

## Browser

## Context 

incognito mode

## Frames

## locator

Locator represents a view to the element(s) on the page. It captures the logic sufficient to retrieve the element at any given moment.

https://playwright.dev/docs/api/class-locator

## selector

Selectors are strings that point to the elements in the page. They are used to perform actions on those elements by means of methods 

https://playwright.dev/python/docs/selectors/#n-th-element-selector

## custom wait
https://playwright.dev/python/docs/navigations

## evaluate

```
Playwright scripts run in your Playwright environment. Your page scripts run in the browser page environment. Those environments don't intersect, they are running in different virtual machines in different processes and even potentially on different computers.

The page.evaluate(expression, **kwargs) API can run a JavaScript function in the context of the web page and bring results back to the Playwright environment. Browser globals like window and document can be used in evaluate.
```

# puppeteer

automation tool and not a test tool. 

uses CDP

use cases such as scraping, generating PDFs, etc.


https://meowni.ca/posts/2017-puppeteer-tests/ (image comparison using visualdiff

https://github.com/puppeteer/puppeteer/blob/main/docs/api.md#pageemulateoptions

screenshot
https://stackoverflow.com/questions/47616985/node-puppeteer-take-screenshot-full-page-spa


# selenium

webdriver protocol

login with selenium

http://carrefax.com/new-blog/2018/2/19/automate-the-browser-with-selenium

# cypress

Cypress runs Javascript in same browser

# chrome extensions

automa https://github.com/Kholid060/automa


