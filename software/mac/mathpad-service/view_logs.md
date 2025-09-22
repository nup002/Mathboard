# View current logs
tail -f /usr/local/var/log/mathpad-service.log

# View error logs  
tail -f /usr/local/var/log/mathpad-service.error.log

# Start service manually
/usr/local/bin/start-mathpad-service

# Stop service
pkill -f mathpad-service

