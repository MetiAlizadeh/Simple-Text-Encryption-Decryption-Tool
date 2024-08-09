# Simple File Encryption/Decryption Tool

This project provides a simple tool for encrypting and decrypting files using two encryption techniques: Caesar Cipher and XOR encryption. The program is designed to be used on Windows, utilizing the `windows.h` library for system calls. 

## Features

- **Caesar Cipher Encryption/Decryption**: Encrypts or decrypts text files using a Caesar Cipher with a variable key.
- **XOR Encryption/Decryption**: Encrypts or decrypts any file using XOR encryption with a variable key.
- **Simple CLI Menu**: Easy-to-use command-line interface that allows the user to choose between encryption and decryption options.

## How to Use

1. **Clone the Repository**:
    ```bash
    git clone https://github.com/yourusername/simple-file-encryption.git
    cd simple-file-encryption
    ```

2. **Compile the Program**:
    Ensure you have a C compiler installed. On Windows, you can use GCC with the following command:
    ```bash
    gcc -o encryptor encryptor.c
    ```

3. **Prepare the Files**:
    - Place the file you want to encrypt in the `result` directory with the name `plaintext.txt`.
    - If decrypting, ensure the file to decrypt is in the `result` directory with the appropriate name (`cipherEncrypted.txt` for Caesar Cipher, `xorEncrypted.txt` for XOR).

4. **Run the Program**:
    ```bash
    ./encryptor
    ```

5. **Choose an Option**:
    - `1`: Encrypt File Using Caesar Cipher
    - `2`: Encrypt File Using XOR
    - `3`: Decrypt File Using Caesar Cipher
    - `4`: Decrypt File Using XOR
    - `5`: Exit

6. **Enter the Key**:
    - The key can be up to 15 characters long. The same key must be used for both encryption and decryption.

7. **Output Files**:
    - The encrypted or decrypted files will be saved in the `result` directory:
        - `cipherEncrypted.txt`: Caesar Cipher encrypted file.
        - `cipherDecrypted.txt`: Caesar Cipher decrypted file.
        - `xorEncrypted.txt`: XOR encrypted file.
        - `xorDecrypted.txt`: XOR decrypted file.

## Example

### Encrypting with Caesar Cipher

1. Select option `1` in the menu.
2. Enter a key (e.g., `key123`).
3. The file `result/plaintext.txt` will be encrypted and saved as `result/cipherEncrypted.txt`.

### Decrypting with Caesar Cipher

1. Select option `3` in the menu.
2. Enter the same key used for encryption.
3. The file `result/cipherEncrypted.txt` will be decrypted and saved as `result/cipherDecrypted.txt`.

### Encrypting with XOR

1. Select option `2` in the menu.
2. Enter a key (e.g., `key123`).
3. The file `result/plaintext.txt` will be encrypted and saved as `result/xorEncrypted.txt`.

### Decrypting with XOR

1. Select option `4` in the menu.
2. Enter the same key used for encryption.
3. The file `result/xorEncrypted.txt` will be decrypted and saved as `result/xorDecrypted.txt`.

## Notes

- This tool assumes that the input files are correctly placed in the `result` directory.
- The tool will overwrite any existing files with the same output filenames without prompt.
- The Caesar Cipher is a basic encryption technique and should not be used for secure encryption in production.
