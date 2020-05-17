

## DNS level redirection using HTTPRED record

add HTTP redirection record in DNS

This is different from DNS CNAME records, because latter cannot point to different FQDN.  

Redirection type
1. 301 standard (final address appears in web browser)
2. 302 temporary 
3. hidden frame (user sees original URL in browser with redirected content in window)


Hard link : During redirection, it will ignore any subdirectories which appear after URL 

HTTP to HTTPS redirection cannot be done at DNS level.  It has to be done at Web server

## redirection at Web server level

HTTP Requests are sent to IP addresses, but include the domain name in the Host Header
```
GET / HTTP/1.1
Host: google.com
```
HTTP servers may serve different content depending on the contents of the Host Header

1. Apache servers can redirect via the .htaccess file http://stackoverflow.com/questions/1100343/apache-redirect-from-non-www-to-www
2. Nginx servers can redirect via server block http://stackoverflow.com/questions/10294481/how-to-redirect-a-url-in-nginx
3. Node.js servers inspect the HTTP Host header, and headers modify the response object

```
response.writeHead(302, {
  'Location': 'your/path/here',
  // optional other headers...
});
response.end();
```

# references

https://en.wikipedia.org/wiki/URL_redirection

https://tools.ietf.org/html/rfc7231#section-6.4
