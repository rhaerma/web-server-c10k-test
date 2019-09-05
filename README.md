# Web Server Performance Test

## Requirements
1. [Apache](https://httpd.apache.org/)
2. [Nginx](https://www.nginx.com/)
3. [Apache Bench for performance test](https://httpd.apache.org/docs/2.4/programs/ab.html)
4. [Libev]()
5. [Tornado]()

## Instalation
### Low Level
1. Run this command to build low level server
    ```
    make low_level
    ```

2. Run this command to run low level server
    ```
    make run_low_level
    ```

### High Level
1. Run this command to run high level server
    ```
    make run_high_level
    ```

## Server Test
1. Turn on web server

   For Apache:
   ```
    sudo service apache2 start
   ```

   For Nginx:
   ```
    sudo service nginx start
   ```

   For Low Level

2. Copy sample html files on `assets` folder to `/var/www/html` folder

3. Execute this command to run 10000 concurrency request test

    ```
    ab -n 10000 -c 10000 http://localhost/500b.html
    ```

## Result

### Apache Test

### Nginx Test

### Low Level Library (Libevent)

### High Level Library (Tornado)

## Author
- Ilma Alifia M. - 13516036
- Erma Safira N. - 13516072
- M. Alif Arifin - 13516078