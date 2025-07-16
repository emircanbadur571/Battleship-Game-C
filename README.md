EN: C implementation of a Battleship Game Simulation for CSE102 Computer Programming course.

TR: CSE102 Bilgisayar Programlama dersi için C dilinde geliştirilmiş Amiral Battı (Battleship) Oyunu Simülasyonu.

# Battleship Game Simulation (C)

\<p align="center"\>
\<img src="[https://img.shields.io/badge/Language-C-blue.svg](https://img.shields.io/badge/Language-C-blue.svg)" alt="C Language"\>
\<img src="[https://img.shields.io/badge/Status-Completed-brightgreen.svg](https://img.shields.io/badge/Status-Completed-brightgreen.svg)" alt="Project Status"\>
\<img src="[https://img.shields.io/badge/License-MIT-blue.svg](https://img.shields.io/badge/License-MIT-blue.svg)" alt="License"\>
\</p\>

## English Description

This project is a C implementation of the classic Battleship game, developed as an assignment for the CSE102 Computer Programming course. The game features a $10 \\times 10$ grid where the user attempts to sink randomly placed ships by firing shots at specific coordinates. The game continues until all ships are sunk.

### Features

  * **Random Ship Placement:** Four ships (1x size 4, 2x size 3, 1x size 2) are randomly placed horizontally or vertically without overlapping.
  * **Interactive Gameplay:** Users input coordinates (e.g., "3 5") to fire shots. The board dynamically updates to show hits ('X') and misses ('O').
  * **Hit/Miss Notifications:** The program informs the user whether their shot was a 'HIT\!' or 'MISS\!'.
  * **Ship Sinking Logic:** A ship is considered sunk only when all its cells have been hit. A message indicates which ship size was destroyed (e.g., "Congratulations\! You have sunk a 4-cell ship\!").
  * **Game Over Condition:** The game concludes when all ships are sunk, displaying the total shots taken.
  * **Logging & Data Saving:**
      * Initial ship positions are saved to `ships.txt`.
      * User moves and game progress (shots and game end) are logged in `battleship_log.txt`.
  * **Replay/Exit Options:** After the game ends, the user can choose to play a new game ('Y' in the code, 'N' in assignment description) or exit ('X').
  * **User Exit at Any Time:** The assignment specifies that the user can quit at any time by entering 'X'. (Current code needs slight modification for mid-game 'X' exit functionality as mentioned in previous response).

### How to Compile and Run

To compile and run this program, you will need a C compiler (like GCC).

1.  **Save the code:** Save the provided C code as `emircan_badur.c` (or `your_program.c` as per assignment requirements).
2.  **Compile:** Open your terminal or command prompt, navigate to the directory where you saved the file, and compile using the following command:
    gcc -o battleship emircan_badur.c
    
    *(Note: The assignment specified `gcc --ansi your_program.c -o your_program`. If you need to strictly adhere to ANSI C, use `--ansi`. The provided code uses some `rand()` functions that might be part of C99 or later, but generally, it should compile with `gcc`.)*
4.  **Run:** Execute the compiled program:
    ./battleship

### File Outputs

The game generates two log files in the same directory as the executable:

  * **`ships.txt`**: Stores the initial random positions of the ships.
  * **`battleship_log.txt`**: Records each shot taken by the player (coordinates and hit/miss status) and the total shots at the end of the game.

## Türkçe Açıklama

Bu proje, CSE102 Bilgisayar Programlama dersi için geliştirilmiş klasik Amiral Battı (Battleship) oyununun C dilinde bir uygulamasıdır. Oyun, kullanıcıların rastgele yerleştirilmiş gemileri belirli koordinatlara atış yaparak batırmaya çalıştığı $10 \\times 10$ bir ızgarayı içerir. Tüm gemiler batırılana kadar oyun devam eder.

### Özellikler

  * **Rastgele Gemi Yerleşimi:** Dört adet gemi (1 adet 4 boyutlu, 2 adet 3 boyutlu, 1 adet 2 boyutlu) çakışmayacak şekilde yatay veya dikey olarak rastgele yerleştirilir.
  * **Etkileşimli Oynanış:** Kullanıcılar atış yapmak için koordinatları (örn: "3 5") girer. Tahta, isabetleri ('X') ve ıskaları ('O') göstermek için dinamik olarak güncellenir.
  * **İsabet/Iska Bildirimleri:** Program, atışın 'HIT\!' (isabet) mi yoksa 'MISS\!' (ıska) mı olduğunu kullanıcıya bildirir.
  * **Gemi Batırma Mantığı:** Bir gemi, yalnızca tüm hücreleri vurulduğunda batmış sayılır. Batan geminin boyutunu belirten bir mesaj gösterilir (örn: "Tebrikler\! 4 hücreli bir gemiyi batırdınız\!").
  * **Oyun Bitiş Durumu:** Tüm gemiler batırıldığında oyun sona erer ve toplam atış sayısı gösterilir.
  * **Günlükleme ve Veri Kaydetme:**
      * Başlangıçtaki gemi pozisyonları `ships.txt` dosyasına kaydedilir.
      * Kullanıcı hareketleri ve oyun ilerlemesi (atışlar ve oyun sonu) `battleship_log.txt` dosyasına kaydedilir.
  * **Yeniden Oyna/Çıkış Seçenekleri:** Oyun bittikten sonra, kullanıcı yeni bir oyun oynamayı ('Y' kodda, ödevde 'N') veya çıkış yapmayı ('X') seçebilir.
  * **İstediği Zaman Çıkış:** Ödev, kullanıcının istediği zaman 'X' tuşuna basarak oyundan çıkabileceğini belirtir. (Mevcut kodda oyun ortasında 'X' ile çıkış işlevi için küçük bir değişiklik gereklidir, önceki yanıtta belirtildiği gibi).

### Derleme ve Çalıştırma

Bu programı derlemek ve çalıştırmak için bir C derleyicisine (örn. GCC) ihtiyacınız olacaktır.

1.  **Kodu Kaydet:** Sağlanan C kodunu `emircan_badur.c` (veya ödev gereksinimlerine göre `your_program.c`) olarak kaydedin.
2.  **Derle:** Terminalinizi veya komut istemcinizi açın, dosyayı kaydettiğiniz dizine gidin ve aşağıdaki komutu kullanarak derleyin:
    gcc -o battleship emircan_badur.c
    *(Not: Ödev `gcc --ansi your_program.c -o your_program` komutunu belirtmiştir. Eğer ANSI C'ye kesinlikle uymanız gerekiyorsa `--ansi` kullanın. Sağlanan kod, C99 veya sonraki sürümlerde bulunan bazı `rand()` işlevlerini kullanır, ancak genellikle `gcc` ile derlenmelidir.)*
3.  **Çalıştır:** Derlenmiş programı çalıştırın:
    ./battleship

### Dosya Çıktıları

Oyun, yürütülebilir dosya ile aynı dizinde iki günlük dosyası oluşturur:

  * **`ships.txt`**: Gemilerin başlangıçtaki rastgele pozisyonlarını saklar.
  * **`battleship_log.txt`**: Oyuncu tarafından yapılan her atışı (koordinatlar ve isabet/ıska durumu) ve oyun sonunda toplam atış sayısını kaydeder.
