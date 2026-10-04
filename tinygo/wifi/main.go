package main

import (
	"fmt"
	"io"
	"time"

	"net/http"

	"tinygo.org/x/drivers/netdev"
	nl "tinygo.org/x/drivers/netlink"
	link "tinygo.org/x/espradio/netlink"
)

var (
	ssid     string
	password string
)

func main() {
	var keepTrying bool = true
	link := &link.Esplink{}
	netdev.UseNetdev(link)

	tries := 0
	connected := false
	for keepTrying {
		fmt.Printf("Connecting to WiFi...[%s:%s]\n", ssid, password)
		err := link.NetConnect(&nl.ConnectParams{
			Ssid:       ssid,
			Passphrase: password,
		})

		if err != nil {
			tries += 1
			if tries == 3 {
				keepTrying = false
			}
			connected = false
			time.Sleep(1 * time.Second)
		} else {
			keepTrying = false
			connected = true
		}
	}

	if connected {
		fmt.Println("Connection Successful!")
		resp, err := http.Get("http://jsonplaceholder.typicode.com/users/10")
		if err != nil {
			fmt.Println("GET request failed!")
		} else {
			fmt.Println(resp.Status)

			body, err := io.ReadAll(resp.Body)
			if err != nil {
				fmt.Printf("ERROR: %s\n", err.Error())
			} else {
				fmt.Println(string(body))
			}
			resp.Body.Close()
		}
	} else {
		fmt.Println("Connection Failed!")
	}

	fmt.Println("The End!")
}
