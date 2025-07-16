# Battleship Game Simulation (C)

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue.svg" alt="C Language">
  <img src="https://img.shields.io/badge/Status-Completed-brightgreen.svg" alt="Project Status">
  <img src="https://img.shields.io/badge/License-MIT-blue.svg" alt="License">
</p>

## English Description

[cite_start]This project is a C implementation of the classic Battleship game, developed as an assignment for the CSE102 Computer Programming course[cite: 1, 2, 3]. [cite_start]The game features a $10 \times 10$ grid where the user attempts to sink randomly placed ships by firing shots at specific coordinates[cite: 6]. [cite_start]The game continues until all ships are sunk[cite: 7].

### Features

* [cite_start]**Random Ship Placement:** Four ships (1x size 4, 2x size 3, 1x size 2) are randomly placed horizontally or vertically without overlapping[cite: 9, 10, 11, 12, 13, 14].
* [cite_start]**Interactive Gameplay:** Users input coordinates (e.g., "3 5") to fire shots[cite: 31]. [cite_start]The board dynamically updates to show hits ('X') and misses ('O')[cite: 29, 32, 33].
* [cite_start]**Hit/Miss Notifications:** The program informs the user whether their shot was a 'HIT!' or 'MISS!'[cite: 17, 32, 33].
* [cite_start]**Ship Sinking Logic:** A ship is considered sunk only when all its cells have been hit[cite: 18, 35]. [cite_start]A message indicates which ship size was destroyed (e.g., "Congratulations! You have sunk a 4-cell ship!")[cite: 23, 37, 38].
* [cite_start]**Game Over Condition:** The game concludes when all ships are sunk, displaying the total shots taken[cite: 39].
* **Logging & Data Saving:**
    * [cite_start]Initial ship positions are saved to `ships.txt`[cite: 20, 28, 41].
    * [cite_start]User moves and game progress (shots and game end) are logged in `battleship_log.txt`[cite: 21, 42].
* [cite_start]**Replay/Exit Options:** After the game ends, the user can choose to play a new game ('Y' in the code, 'N' in assignment description) or exit ('X')[cite: 24, 45].
* [cite_start]**User Exit at Any Time:** The assignment specifies that the user can quit at any time by entering 'X'[cite: 22, 44]. (Current code needs slight modification for mid-game 'X' exit functionality as mentioned in previous response).

### How to Compile and Run

To compile and run this program, you will need a C compiler (like GCC).

1.  [cite_start]**Save the code:** Save the provided C code as `emircan_badur.c` (or `your_program.c` as per assignment requirements [cite: 48]).
2.  **Compile:** Open your terminal or command prompt, navigate to the directory where you saved the file, and compile using the following command:
    ```bash
    gcc -o battleship emircan_badur.c
    ```
    [cite_start]*(Note: The assignment specified `gcc --ansi your_program.c -o your_program`[cite: 52]. If you need to strictly adhere to ANSI C, use `--ansi`. The provided code uses some `rand()` functions that might be part of C99 or later, but generally, it should compile with `gcc`.)*
3.  **Run:** Execute the compiled program:
    ```bash
    ./battleship
    ```

### File Outputs

The game generates two log files in the same directory as the executable:

* [cite_start]**`ships.txt`**: Stores the initial random positions of the ships[cite: 20, 28, 41].
* [cite_start]**`battleship_log.txt`**: Records each shot taken by the player (coordinates and hit/miss status) and the total shots at the end of the game[cite: 21, 42].

---

## Türkçe Açıklama

[cite_start]Bu proje, CSE102 Bilgisayar Programlama dersi için geliştirilmiş klasik Amiral Battı (Battleship) oyununun C dilinde bir uygulamasıdır[cite: 1, 2, 3]. [cite_start]Oyun, kullanıcıların rastgele yerleştirilmiş gemileri belirli koordinatlara atış yaparak batırmaya çalıştığı $10 \times 10$ bir ızgarayı içerir[cite: 6]. [cite_start]Tüm gemiler batırılana kadar oyun devam eder[cite: 7].

### Özellikler

* [cite_start]**Rastgele Gemi Yerleşimi:** Dört adet gemi (1 adet 4 boyutlu, 2 adet 3 boyutlu, 1 adet 2 boyutlu) çakışmayacak şekilde yatay veya dikey olarak rastgele yerleştirilir[cite: 9, 10, 11, 12, 13, 14].
* [cite_start]**Etkileşimli Oynanış:** Kullanıcılar atış yapmak için koordinatları (örn: "3 5") girer[cite: 31]. [cite_start]Tahta, isabetleri ('X') ve ıskaları ('O') göstermek için dinamik olarak güncellenir[cite: 29, 32, 33].
* **İsabet/Iska Bildirimleri:** Program, atışın 'HIT!' (isabet) mi yoksa 'MISS!' [cite_start](ıska) mı olduğunu kullanıcıya bildirir[cite: 17, 32, 33].
* [cite_start]**Gemi Batırma Mantığı:** Bir gemi, yalnızca tüm hücreleri vurulduğunda batmış sayılır[cite: 18, 35]. [cite_start]Batan geminin boyutunu belirten bir mesaj gösterilir (örn: "Tebrikler! 4 hücreli bir gemiyi batırdınız!")[cite: 23, 37, 38].
* [cite_start]**Oyun Bitiş Durumu:** Tüm gemiler batırıldığında oyun sona erer ve toplam atış sayısı gösterilir[cite: 39].
* **Günlükleme ve Veri Kaydetme:**
    * [cite_start]Başlangıçtaki gemi pozisyonları `ships.txt` dosyasına kaydedilir[cite: 20, 28, 41].
    * [cite_start]Kullanıcı hareketleri ve oyun ilerlemesi (atışlar ve oyun sonu) `battleship_log.txt` dosyasına kaydedilir[cite: 21, 42].
* [cite_start]**Yeniden Oyna/Çıkış Seçenekleri:** Oyun bittikten sonra, kullanıcı yeni bir oyun oynamayı ('Y' kodda, ödevde 'N') veya çıkış yapmayı ('X') seçebilir[cite: 24, 45].
* [cite_start]**İstediği Zaman Çıkış:** Ödev, kullanıcının istediği zaman 'X' tuşuna basarak oyundan çıkabileceğini belirtir[cite: 22, 44]. (Mevcut kodda oyun ortasında 'X' ile çıkış işlevi için küçük bir değişiklik gereklidir, önceki yanıtta belirtildiği gibi).

### Derleme ve Çalıştırma

Bu programı derlemek ve çalıştırmak için bir C derleyicisine (örn. GCC) ihtiyacınız olacaktır.

1.  [cite_start]**Kodu Kaydet:** Sağlanan C kodunu `emircan_badur.c` (veya ödev gereksinimlerine göre `your_program.c` [cite: 48]) olarak kaydedin.
2.  **Derle:** Terminalinizi veya komut istemcinizi açın, dosyayı kaydettiğiniz dizine gidin ve aşağıdaki komutu kullanarak derleyin:
    ```bash
    gcc -o battleship emircan_badur.c
    ```
    [cite_start]*(Not: Ödev `gcc --ansi your_program.c -o your_program` [cite: 52] komutunu belirtmiştir. Eğer ANSI C'ye kesinlikle uymanız gerekiyorsa `--ansi` kullanın. Sağlanan kod, C99 veya sonraki sürümlerde bulunan bazı `rand()` işlevlerini kullanır, ancak genellikle `gcc` ile derlenmelidir.)*
3.  **Çalıştır:** Derlenmiş programı çalıştırın:
    ```bash
    ./battleship
    ```

### Dosya Çıktıları

Oyun, yürütülebilir dosya ile aynı dizinde iki günlük dosyası oluşturur:

* [cite_start]**`ships.txt`**: Gemilerin başlangıçtaki rastgele pozisyonlarını saklar[cite: 20, 28, 41].
* [cite_start]**`battleship_log.txt`**: Oyuncu tarafından yapılan her atışı (koordinatlar ve isabet/ıska durumu) ve oyun sonunda toplam atış sayısını kaydeder[cite: 21, 42].
