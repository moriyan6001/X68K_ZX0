# X68K_FDBoot

ZX0フォーマットのファイルをX68000で展開してみるテストコードです

## ファイル構成

- main.c ... メインプログラム（エラー処理は省いています）
- go.bat ... コンパイルするだけのバッチファイル
- DecompressZX0.s ... C言語とアセンブラの橋渡し
- unzx0_68000.s ... デコーダ本体

## 関連記事

https://zenn.dev/morian/articles/ab313ec56c4c4f
