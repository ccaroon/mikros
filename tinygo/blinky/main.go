package main

import (
	"fmt"
	"machine"
	"time"
)

func main() {
	led := machine.D0
	led.Configure(
		machine.PinConfig{
			Mode: machine.PinOutput,
		},
	)

	for {
		fmt.Println("ON")
		led.High()
		time.Sleep(time.Second)

		fmt.Println("OFF")
		led.Low()
		time.Sleep(time.Second)
	}
}
