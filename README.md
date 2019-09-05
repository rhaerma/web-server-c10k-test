# Web Server Performance Test

## Requirements
1. Apache
2. Nginx
3. Apache Bench for performance test

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
2. Copy sample html files on `assets` folder to `/var/www/html` folder
3. Execute this command to run 10000 concurrency request test
```
    ab -n 10000 -c 10000 http://localhost/500b.html
```

## Nginx Test

## Low Level Library

## High Level Library

## Author
- Ilma Alifia M. - 13516036
- Erma Safira N. - 13516072
- M. Alif Arifin - 13516078