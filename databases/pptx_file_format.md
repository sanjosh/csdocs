
pptx is zip file with each file being xml

```
mv file.pptx file.zip
unzip file.zip

```
PPTX structure is outlined in OOXML standards ECMA-376 and ISO/IEC IS 29500:2008.

```
Presentation.xml – contains definition of the presentation
Presentation.xml.rel – contains relationships of presentation to the other parts of the content such as slideMaster1.xml, notesMaster1.xml, handoutMaster1.xml, slide1.xml, presProps.xml, tableStyles.xml, theme1.xml, as well as the URIs for external links.
presProps.xml – contains presentation properties.
“slideLayouts” folder – contains information about presentation slides layout.
Theme1.xml – information about presentation theme. Theme can contain information about fonts, format schemes, color schemes and more.
```

## reader

python-pptx

## pretty print

```
xmllint --format emails.xml
```
