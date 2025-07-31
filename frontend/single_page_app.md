

# SPA versus server side

Loads a single HTML page and dynamically updates the content using JavaScript without reloading the entire page from the server.



```
You go to https://app.example.com/

The page loads a JavaScript app (e.g., built with React).

You click “Profile” — instead of loading /profile from the server, the app:

Uses JavaScript to render the profile page.

Sends a background API request like GET /api/user/profile.
```
 
# client-side routing to create separate urls for each function

react router

# When SPA Does Make Sense

Complex UI interactions (drag/drop, live filtering)

Real-time data updates (chats, dashboards)

Desktop-like experience (Gmail, Figma)

Apps with minimal public SEO needs

# SEO and indexing challenges

Sites like blogs, documentation, news, or static info pages don’t need real-time UI updates or complex interactivity.


# complexity

SPAs need client-side routing, history management, scroll position restoration, etc.

As the app grows, maintaining global app state (Redux, Zustand, Vuex) gets tricky.

# browser

If JS fails to load or is disabled, SPAs show blank screens.

Mobile browsers with strict energy-saving modes may throttle JS execution.

# security

SPAs handle authentication, tokens (JWT), and access control entirely client-side.

# difference


SSG	: html generated at Build time	Blogs; landing pages
SSR	: html at Request time (server-side);	E-commerce product pages
CSR (SPA) : html at	In the browser via JS;	Interactive apps (e.g., dashboards)
MPA	: html at Per page (traditional);	Classic websites, forms

