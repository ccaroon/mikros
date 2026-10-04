//go:build mage

package main

import (
	"fmt"
	"os"

	"github.com/magefile/mage/sh"
)

var tinyGo = sh.RunCmd("tinygo")

// So that the output of the commands will go to STDOUT
var _ = os.Setenv("MAGEFILE_VERBOSE", "true")

func Build() error {
	return tinyGo("build", "-target", "xiao-esp32c3", ".")
}

func Install(monitor *bool, ssid string, password string) error {
	var monFlag string

	if monitor != nil {
		monFlag = "-monitor"
	}

	ldFlags := fmt.Sprintf("-X main.ssid=%s -X main.password=%s", ssid, password)

	return tinyGo(
		"flash", monFlag, "-size", "short",
		"-target", "xiao-esp32c3",
		"-ldflags", ldFlags,
		".",
	)
}
