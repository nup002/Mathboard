# Key Switches

[:globe_with_meridians:English](/README.md)

此為機械鍵盤鍵軸的 [KiCad](https://www.kicad.org/) Footprint 庫，以 [MIT 授權許可](/LICENSE)發佈。

## 用法

建議搭配 [KiCAD KLE Placer](https://github.com/zykrah/kicad-kle-placer) 或 [kicad-kbplacer](https://github.com/adamws/kicad-kbplacer) 使用本庫，以自動擺放鍵軸。

如果你在使用 Git，你可以將本庫作爲 [submodule](https://git-scm.com/docs/git-submodule) 使用，指令爲：`git submodule add https://github.com/siderakb/key-switches.pretty.git`

使用本庫所製作的鍵盤：[ErgoSNM](https://github.com/siderakb/ergo-snm-keyboard)、[Calcite](https://github.com/siderakb/calcite)。

## 兼容表

|           預覽 [^preview]            | Footprint [^sw-prefix]                   |         Cherry MX         | Cherry MX Low Profile |         TTC KS32         |  Kailh Choc V1 [^k-choc1]   |  Kailh Choc V2 [^k-choc2]  | Gateron Low Profile [^g-lp] |     THT [^tht]     |       熱插拔       | *nSilk* 變體 [^ns-suffix] | *swap* 變體 [^swap-suffix] |
| :----------------------------------: | ---------------------------------------- | :-----------------------: | :-------------------: | :----------------------: | :-------------------------: | :------------------------: | :-------------------------: | :----------------: | :----------------: | :-----------------------: | :------------------------: |
| ![](https://i.imgur.com/5enIXui.png) | MX_THT                                   |    :white_check_mark:     |                       |                          |                             |                            |                             | :white_check_mark: |                    |    :white_check_mark:     |                            |
| ![](https://i.imgur.com/gQgppii.jpg) | MX_HotSwap_THT                           |    :white_check_mark:     |                       |                          |                             |                            |                             | :white_check_mark: | :white_check_mark: |    :white_check_mark:     |                            |
| ![](https://i.imgur.com/Se1CHMa.jpg) | MX_HotSwap_THT_double                    |    :white_check_mark:     |                       |                          |                             |                            |                             | :white_check_mark: | :white_check_mark: |                           |                            |
| ![](https://i.imgur.com/pFtTYBV.jpg) | MX_HotSwap_THT_double_alt1               |    :white_check_mark:     |                       |                          |                             |                            |                             | :white_check_mark: | :white_check_mark: |                           |                            |
| ![](https://i.imgur.com/wPHmvjv.jpg) | MX_HotSwap_THT_double_alt2               |    :white_check_mark:     |                       |                          |                             |                            |                             | :white_check_mark: | :white_check_mark: |                           |                            |
| ![](https://i.imgur.com/ySLGt4U.jpg) | MX_HotSwap_PTH                           |    :white_check_mark:     |                       |                          |                             |                            |                             |   :bulb: [^pth]    | :white_check_mark: |    :white_check_mark:     |     :white_check_mark:     |
| ![](https://i.imgur.com/UiA5tTy.jpg) | MX_HotSwap_PTH_double                    |    :white_check_mark:     |                       |                          |                             |                            |                             |   :bulb: [^pth]    | :white_check_mark: |                           |                            |
| ![](https://i.imgur.com/prosQX5.jpg) | MX_LowProfile_THT                        |                           |  :white_check_mark:   | :bulb: [^t-ks_vs_c-mxlp] |                             |                            |                             | :white_check_mark: |                    |    :white_check_mark:     |                            |
| ![](https://i.imgur.com/La8fbI2.png) | Gateron_LowProfile_THT                   |                           |                       |                          |                             |                            |     :white_check_mark:      | :white_check_mark: |                    |                           |                            |
| ![](https://i.imgur.com/rRUIFk0.png) | Gateron_LowProfile_HotSwap_THT           |                           |                       |                          |                             |                            |     :white_check_mark:      | :white_check_mark: | :white_check_mark: |                           |                            |
| ![](https://i.imgur.com/7FCzjra.png) | Gateron_LowProfile_HotSwap_PTH           |                           |                       |                          |                             |                            |     :white_check_mark:      |   :bulb: [^pth]    | :white_check_mark: |                           |                            |
| ![](https://i.imgur.com/mveqvbo.png) | Kailh_Choc_V1_THT                        |                           |                       |                          |     :white_check_mark:      |                            |                             | :white_check_mark: |                    |    :white_check_mark:     |     :white_check_mark:     |
| ![](https://i.imgur.com/Dbh3t1w.png) | Kailh_Choc_V1_THT_alt1                   |                           |                       |                          |     :white_check_mark:      |                            |                             | :white_check_mark: |                    |                           |                            |
| ![](https://i.imgur.com/1nT0rZy.png) | Kailh_Choc_V1_HotSwap                    |                           |                       |                          |     :white_check_mark:      |                            |                             |                    | :white_check_mark: |    :white_check_mark:     |                            |
| ![](https://i.imgur.com/2R0aWFC.png) | Kailh_Choc_V1_HotSwap_THT                |                           |                       |                          |     :white_check_mark:      |                            |                             | :white_check_mark: | :white_check_mark: |                           |                            |
| ![](https://i.imgur.com/1LEHowc.png) | Kailh_Choc_V1_HotSwap_PTH                |                           |                       |                          |     :white_check_mark:      |                            |                             |   :bulb: [^pth]    | :white_check_mark: |                           |                            |
| ![](https://i.imgur.com/mK65Vrx.jpg) | Kailh_Choc_V2_THT                        |                           |                       |                          |                             |     :white_check_mark:     |                             | :white_check_mark: |                    |    :white_check_mark:     |                            |
| ![](https://i.imgur.com/DStr5La.jpg) | Kailh_Choc_V1V2_THT_Hybrid               |                           |                       |                          | :bulb:[^k-choc1_vs_k-choc2] |     :white_check_mark:     |                             | :white_check_mark: |                    |                           |                            |
| ![](https://i.imgur.com/1l7HB0J.png) | MX_Kailh_Choc_V1V2_THT_Hybrid            | :bulb: [^c-mx_vs_k-choc2] |                       |                          | :bulb:[^k-choc1_vs_k-choc2] |     :white_check_mark:     |                             | :white_check_mark: |                    |                           |                            |
| ![](https://i.imgur.com/9mmCyuX.jpg) | MX_LowProfile_Kailh_Choc_V1V2_THT_Hybrid |                           |  :white_check_mark:   | :bulb: [^t-ks_vs_c-mxlp] | :bulb:[^k-choc1_vs_k-choc2] | :bulb:[^k-choc2_vs_c-mxlp] |                             | :white_check_mark: |                    |                           |                            |

> :white_check_mark:: 兼容; :bulb:: 有條件的兼容; 空白: 不兼容.


[^preview]: 預覽圖片僅供參考，不一定會隨 Footprint 更新。
[^tht]: THT 代表通孔焊接。
[^pth]: PTH 代表熱插拔座的孔壁有電鍍，鍵軸也可以在無熱插拔座的情況下直接焊接，但是其焊接難度會比標準 THT 版本更高。
[^k-choc1]: Kailh Choc V1 也稱為 PG1350。
[^k-choc2]: Kailh Choc V2 也稱為 PG1353。
[^g-lp]: Gateron Low Profile  1.0（又名 KS-27）與 2.0（又名 KS-33）的 Footprint 互相兼容。
[^t-ks_vs_c-mxlp]: TTC KS32 與 Cherry MX Low Profile 非常相似，基本上兼容。
[^k-choc1_vs_k-choc2]: Choc V1 的中央固定銷比 Choc V2 還小，但是 Choc V1 有另外兩個固定銷，所以足夠穩定。
[^k-choc2_vs_c-mxlp]: Choc V2 的中央固定銷比 Cherry MX Low Profile 還小，Choc V2 可能無法固定得很穩。
[^c-mx_vs_k-choc2]: Cherry MX 的中央固定銷比 Choc V2 還小，但是有些 Cherry MX 有另外兩個固定銷，所以足夠穩定。
[^sw-prefix]: 省略 Footprint 名稱中的 "SW" 前綴。
[^ns-suffix]: 帶有 "nSilk" 後綴的 Footprint 代表沒有頂層絲印。
[^swap-suffix]: 帶有 "swap" 後綴的 Footprint 代表接腳編號互換。
