//go:build mage

package main

import (
	"os"

	"github.com/magefile/mage/sh"
)

var tinyGo = sh.RunCmd("tinygo")

// So that the output of the commands will go to STDOUT
var _ = os.Setenv("MAGEFILE_VERBOSE", "true")

func Build() error {
	return tinyGo("build", "-target", "xiao-esp32c3", ".")
}

func Install() error {
	return tinyGo("flash", "-target", "xiao-esp32c3", ".")
}
