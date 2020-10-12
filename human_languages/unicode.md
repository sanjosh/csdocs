
# Intro

Unicode assigns a number to every character in any language.  Its map characters to numbers.

Upper case and lower-case

Idiosyncrasies : Same character can be represented in two different ways

Emoji

Control characters

http://kunststube.net/encoding/

https://en.wikipedia.org/wiki/Unicode_control_characters#Bidirectional_text_control
 

http://userguide.icu-project.org/unicode

https://www.rapidtables.com/code/text/unicode-characters.html

https://media.readthedocs.org/pdf/unicodebook/latest/unicodebook.pdf

http://www.unicode.org/charts/

https://www.yourhtmlsource.com/text/specialcharacters.html

https://en.wikipedia.org/wiki/List_of_Unicode_characters

## Whitespace Unicode

https://en.wikipedia.org/wiki/Whitespace_character

# Encoding

It is the encoding which maps the Unicode numbers to specific byte sequences. 

There are many encodings like UTF-8, UTF-16, UCS-2

If you read a Unicode sequence using the wrong encoding, you can get garbage.  That is why we have Content-Type in HTML docs.
 
# Escape sequences

They exist because certain characters are special in any language or document format.

https://stackoverflow.com/questions/7381974/which-characters-need-to-be-escaped-on-html

https://en.wikipedia.org/wiki/Escape_sequences_in_C
 
## Numeric reference

In HTML/SGML/XML, characters can be represented by a numerical code (e.g. "&#<number>;")
https://en.wikipedia.org/wiki/Numeric_character_reference

## Character reference

In XML, characters can also be represented by predefined symbols (e.g. "&amp;")
https://en.wikipedia.org/wiki/Character_encodings_in_HTML

## Unicode escape


Unicode escape sequence is \u

https://stackoverflow.com/questions/33415388/whats-the-difference-between-hex-code-x-and-unicode-u-chars

https://javajee.com/unicode-escapes-in-java

# Programming issues

https://www.joelonsoftware.com/2005/05/11/making-wrong-code-look-wrong/

https://www.owasp.org/index.php/Secure_Coding_Cheat_Sheet

## How to take input

## How to store Unicode

## How to output

# Language support

## Java

regex

Character class

https://commons.apache.org/proper/commons-lang/apidocs/index.html?org/apache/commons/lang3/StringEscapeUtils.html

https://www.regular-expressions.info/posixbrackets.html

icu4j

## Javascript

## C/C++
