open Express;

let app = express();

App.get(app, ~path="/") @@ Middleware.from((_req, _next) => Response.sendString("Hello world!"));

let onListen = e =>
  switch (e) {
  | exception (Js.Exn.Error(e)) =>
    Js.log(e);
    Node.Process.exit(1);
  | _ => Js.log @@ "Listening at http://127.0.0.1:3000"
  };

let server = App.listen(app, ~port=3000, ~onListen, ());
