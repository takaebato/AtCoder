# String / Char

## 変換
- char -> int
  ```cpp
  c - '0'
  c - 'a'
  ```
- char -> char (アルファベット移動) 
  - ※ ASCII: 数字->大文字アルファベット->小文字アルファベット の順序
  ```cpp
  char('a' + num) // constructor
  (char)('a' + num) // cast
  ```
- char -> string
  ```cpp
  string s(c); // constructor
  string(1, c); // 特殊なconstructor
  ```
- int -> char
  ```cpp
  char('0' + num) // 一桁限定なことに注意。2桁以上になると別の文字になる。
  ```
- int -> string
  ```cpp
  to_string(i);
  ```

## 操作
- 検索: s.find
  ```cpp
  if(s.find(x)==string::npos){ } // if not found
  ```
- スライス: s.substr(start, num)
  ```cpp
  string s = "abcd";
  s.substr(1);    // "bcd"
  s.substr(1, 2); // "bc" index 1から2文字取得
  ```


