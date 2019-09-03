#include <sys/types.h>
#include <sys/time.h>
#include <sys/queue.h>
#include <stdlib.h>
#include <err.h>
#include <event.h>
#include <evhttp.h>
#include <stdio.h>
#include <string>
using namespace std;

const int PORT = 8080;

evbuffer * copy_data (const char* file_name) {
    FILE * fp;
    int fd, sz;
    struct evbuffer *buf;

    buf = evbuffer_new();
    if (buf == NULL) {
        err(1, "failed to create response buffer");
    }

    // open file
    fp = fopen(file_name, "r");
    // find size file
    fd = fileno(fp);
    fseek(fp, 0L, SEEK_END);
    sz = ftell(fp);
    // copy data to buffer
    evbuffer_add_file(buf, fd, 0, sz);

    return buf;
}

void request_handler(struct evhttp_request *req, void *arg)
{
    struct evbuffer *buf;
    string s_req(evhttp_request_uri(req));  

    if (s_req.compare("/500b") == 0) {
        buf = copy_data("./assets/500b.html");
        evhttp_send_reply(req, HTTP_OK, "OK", buf);
    } else if (s_req.compare("/20k")==0){
        buf = copy_data("./assets/20k.html");
        evhttp_send_reply(req, HTTP_OK, "OK", buf);
    } else if (s_req.compare("/test")==0){
        buf = copy_data("./assets/test.html");
        evhttp_send_reply(req, HTTP_OK, "OK", buf);
    } else {
        evhttp_send_error(req, 404, "File not found");
    }
}

int main(int argc, char **argv) {
    struct evhttp *httpd;

    // init
    event_init();
    httpd = evhttp_start("0.0.0.0", PORT);

    printf("Listening on port: %d\n", PORT);

    evhttp_set_gencb(httpd, request_handler, NULL);

    event_dispatch();
    evhttp_free(httpd);

    return 0;   
}