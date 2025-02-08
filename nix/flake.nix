{
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixpkgs-unstable";
  };

  outputs = { self, nixpkgs, ... }@inputs:
    let
      system = "x86_64-linux";
      pkgs = import nixpkgs {
        inherit system;
        config.allowUnsupportedSystem = true;
      };
    in {
      devShells.x86_64-linux.default = pkgs.mkShell {
        WINEPREFIX="/home/llll/src/crook/wineprefix";
        buildInputs = [
          pkgs.wineWowPackages.stable
          pkgs.gnumake
          pkgs.pkgsCross.mingwW64.buildPackages.gcc
          pkgs.pkgsCross.mingwW64.buildPackages.gdb
          pkgs.pkgsCross.mingwW64.capstone
          pkgs.pkgsCross.mingw32.buildPackages.gcc
          pkgs.pkgsCross.mingw32.capstone
          pkgs.yasm
        ];
      };
    };
}
