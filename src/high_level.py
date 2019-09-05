import tornado.ioloop
import tornado.web
from tornado.options import options, define

define("port", default=9000, help="TCP port to listen on")

class MainHandler(tornado.web.RequestHandler):
    def get(self):
        self.write("Haloooo TORNADOOOOO")

class file20k(tornado.web.RequestHandler):
    def get(self):
        self.render('../assets/20k.html')
        self.on_connection_close()

class file500b(tornado.web.RequestHandler):
    def get(self):
        self.render('../assets/500b.html')

def make_app():
    return tornado.web.Application([
        (r"/", MainHandler),
        (r"/20k", file20k),
        (r"/500b", file500b),
    ], debug=True)

if __name__ == "__main__":
    app = make_app()
    app.listen(options.port)
    tornado.ioloop.IOLoop.current().start()
    