# encriptar-C++
Este código en C++ utiliza la librería Crypto++ para encriptar una contraseña utilizando el algoritmo de cifrado AES en modo CBC (Cipher Block Chaining). AES (Advanced Encryption Standard) es un algoritmo de cifrado simétrico ampliamente utilizado para asegurar la confidencialidad de los datos.

La función EncryptPassword recibe dos parámetros: password que es la contraseña a encriptar, y encryptionKey que es la clave de cifrado utilizada para el algoritmo AES. Esta función devuelve una cadena de texto que representa la contraseña encriptada.

Dentro de la función EncryptPassword, se realiza la encriptación de la contraseña utilizando AES en modo CBC. Se inicializan las estructuras key e iv con ceros. Luego, se crea una instancia de CryptoPP::AES::Encryption con la clave de cifrado encryptionKey. A continuación, se configura el modo CBC y se utiliza CryptoPP::StreamTransformationFilter para realizar la encriptación.

La contraseña original se coloca en el filtro de transformación stfEncryptor y se procesa mediante la función Put. Luego, se llama a MessageEnd para finalizar la encriptación.

La contraseña encriptada se almacena en la variable encryptedPassword, que luego es devuelta por la función.

En la función main, se define una contraseña (password) y una clave de cifrado (encryptionKey). Luego, se llama a EncryptPassword para encriptar la contraseña utilizando la clave proporcionada.

Finalmente, se imprime la contraseña original y la contraseña encriptada en la consola.
