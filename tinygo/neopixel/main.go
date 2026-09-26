package main

import (
	"fmt"
	"image/color"
	"machine"
	"time"

	"math/rand"

	"tinygo.org/x/drivers/ws2812"
)

const numLEDS = 5

func main() {
	pin := machine.D0
	pin.Configure(
		machine.PinConfig{Mode: machine.PinOutput},
	)

	neo := ws2812.NewWS2812(pin)
	// leds := []color.RGBA{
	// 	{R: 255, G: 0, B: 0},
	// 	{R: 0, G: 255, B: 0},
	// 	{R: 0, G: 0, B: 255},
	// 	{R: 255, G: 255, B: 0},
	// 	{R: 0, G: 255, B: 255},
	// }

	fmt.Println("NeoPixel Test")

	leds := make([]color.RGBA, numLEDS, numLEDS)
	for {
		now := time.Now()
		// fmt.Println(now)

		for i := range numLEDS {
			red := uint8(rand.Intn(255))
			green := uint8(rand.Intn(255))
			blue := uint8(rand.Intn(255))
			// fmt.Printf("[%d, %d, %d]\n", red, green, blue)

			leds[i] = color.RGBA{R: red, G: green, B: blue}
		}

		ledIdx := now.Second() % numLEDS
		leds[ledIdx] = color.RGBA{R: 0, G: 255, B: 0}

		neo.WriteColors(leds)

		time.Sleep(time.Second)
	}

}
