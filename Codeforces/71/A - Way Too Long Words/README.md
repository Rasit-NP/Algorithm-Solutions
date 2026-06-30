# [Way Too Long Words](https://codeforces.com/contest/71/problem/A)

### Limits

time: 1s, memory: 256 megabytes

## Problem

Sometimes some words like "`localization`" or "`internationalization`" are so long that writing them many times in one text is quite tiresome.

Let's consider a word too long, if its length is strictly more than 10 characters. All too long words should be replaced with a special abbreviation.

This abbreviation is made like this: we write down the first and the last letter of a word and between them we write the number of letters between the first and the last letters. That number is in decimal system and doesn't contain any leading zeroes.

Thus, "`localization`" will be spelt as "`l10n`", and "`internationalization`» will be spelt as "`i18n`".

You are suggested to automatize the process of changing the words with abbreviations. At that all too long words should be replaced by the abbreviation and the words that are not too long should not undergo any changes.

### Input

The first line contains an integer _n_ (1 ≤ _n_ ≤ 100). Each of the following _n_ lines contains one word. All the words consist of lowercase Latin letters and possess the lengths of from 1 to 100 characters.

### Output

Print _n_ lines. The _i_\-th line should contain the result of replacing of the _i_\-th word from the input data.

## Examples
### Input
```
4wordlocalizationinternationalizationpneumonoultramicroscopicsilicovolcanoconiosis
```

### Output
```
wordl10ni18np43s
```