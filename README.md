# Web Server Performance Test

## Requirements
1. [Apache](https://httpd.apache.org/)
2. [Nginx](https://www.nginx.com/)
3. [Apache Bench for performance test](https://httpd.apache.org/docs/2.4/programs/ab.html)
4. [Libevent](https://libevent.org/)
5. [Tornado](https://www.tornadoweb.org/en/stable/)

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
1. 500 bytes HTML file
| Experiment | Time per Request (avg) | Total Time Taken | Memory Usage |
|------------|------------------------|------------------|--------------|
| 1          | 0.061 ms               | 0.613 s          | 0.14 GB      |
| 2          | 0.049 ms               | 0.490 s          | 0.15 GB      |
| 3          | 0.049 ms               | 0.485 s          | 0.14 GB      |

### Nginx Test

### Low Level Library (Libevent)
1. 500 bytes HTML file
| Experiment | Time per Request (avg) | Total Time Taken | Memory Usage |
|------------|------------------------|------------------|--------------|
| 1          | 0.128 ms               | 1.278 s          | 0.20 GB      |
| 2          | 0.110 ms               | 1.102 s          | 0.19 GB      |
| 3          | 0.113 ms               | 1.129 s          | 0.19 GB      |

2. 20 kilobytes HTML file
| Experiment | Time per Request (avg) | Total Time Taken | Memory Usage |
|------------|------------------------|------------------|--------------|
| 1          | 0.124 ms               | 1.243 s          | 0.18 GB      |
| 2          | 0.131 ms               | 1.312 s          | 0.19 GB      |
| 3          | 0.120 ms               | 1.197 s          | 0.20 GB      |

### High Level Library (Tornado)

## Author
- Ilma Alifia M. - 13516036
- Erma Safira N. - 13516072
- M. Alif Arifin - 13516078