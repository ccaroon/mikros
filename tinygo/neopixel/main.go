package main

import (
	"image/color"
	"machine"

	"tinygo.org/x/drivers/ws2812"
)

func main() {
	pin := machine.D0
	pin.Configure(
		machine.PinConfig{Mode: machine.PinOutput},
	)

	neo := ws2812.New(pin)
	leds := []color.RGBA{
		{R: 255, G: 0, B: 0},
		{R: 0, G: 255, B: 0},
		{R: 0, G: 0, B: 255},
		{R: 255, G: 255, B: 0},
		{R: 0, G: 255, B: 255},
	}

	neo.WriteColors(leds)

}
