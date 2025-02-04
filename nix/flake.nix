{
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixpkgs-unstable";
  };

  outputs = { self, nixpkgs, ... }@inputs:
    let
      system = "x86_64-linux";
      pkgs = nixpkgs.legacyPackages.${system};
    in {
      devShells.x86_64-linux.default = pkgs.mkShell {
        WINEPREFIX="/home/llll/src/crook/wineprefix";
        buildInputs = [
          pkgs.wine64
          pkgs.gnumake
          pkgs.pkgsCross.mingwW64.buildPackages.gcc
          pkgs.yasm
        ];
      };
    };
}
