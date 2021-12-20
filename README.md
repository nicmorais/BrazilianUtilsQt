# BrazilianUtilsQt

Inspired by [brazilian-utils](https://github.com/brazilian-utils/brazilian-utils "brazilian-utils"). Boleto validator algorithm by: [boleto-brasileiro-validator](https://github.com/mcrvaz/boleto-brasileiro-validator "boleto-brasileiro-validator")
### Features
* CPF validator
* CNPJ validator
* [Boleto](https://en.wikipedia.org/wiki/Boleto "Boleto") Validator (Bancário/Arrecadação)
* Capitalize (ignores prepositions, rewrites acronyms and abbreviations in upper case)
* CPF generator

TODO: CNPJ generator

### Usage
```cpp
BrazilianUtilsQt::isValidCpf("52458454402") //true
BrazilianUtilsQt::isValidCnpj("68718934000105") //true
BrazilianUtilsQt::isValidCpf("524.584.544-02") //true
BrazilianUtilsQt::isValidCnpj("68.718.934/0001-05") //true
```
