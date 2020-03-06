const net = require('net');

const server = net.createServer((socket) => {
	socket.on('data', (data) => {
		console.log(data.toString('utf-8'));
		socket.write('hi');
	});
	socket.on('error', (data) => {
		console.log('disconnected');
	});
});

server.listen(8124, () => {
	console.log('listening on 8124...');
});

server.on('connection', () => {
	console.log('someone is connecting...');
});

