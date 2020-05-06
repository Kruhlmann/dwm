# This is an example PKGBUILD file. Use this as a start to creating your own,
# and remove these comments. For more information, see 'man PKGBUILD'.
# NOTE: Please fill out the license field for your package! If it is unknown,
# then please put 'unknown'.

# Maintainer: Andreas Kruhlmann <echo "YW5kcmVhc0BrcnVobG1hbm4uZGV2Cg==" | base64 -d>
pkgname=dwm-kruhlmann-git
pkgver=6.2.r1706.b2e4bd2
pkgrel=1
epoch=
pkgdesc="Andreas Kruhlmann's DWM fork with an assortment of patches applied"
arch=(x86_64 i686)
url="https://github.com/Kruhlmann/dwm"
license=('MIT')
groups=()
depends=()
makedepends=(make git)
checkdepends=()
optdepends=()
provides=(dwm)
conflicts=(dwm)
replaces=()
backup=()
options=()
install=
changelog=
source=("git+$url")
noextract=()
md5sums=('SKIP')
validpgpkeys=()

pkgver() {
	cd "${_pkgname}"
    printf "6.2.r%s.%s" "$(git rev-list --count HEAD)" "$(git rev-parse --short HEAD)"
}

build() {
	cd "${_pkgname}"
    make X11INC=/usr/include/X11 X11LIB=/usr/lib/X11
}

package() {
	cd "${_pkgname}"
    mkdir -p ${pkgdir}/opt/${pkgname}
    mkdir -rf * ${pkgdir}/opt/${pkgname}
	make PREFIX=/usr DESTDIR="${pkgdir}" install
    install -Dm644 LICENSE "${pkgdir}/usr/share/licenses/${pkgname}/LICENSE"
    install -Dm644 README.MD "${pkgdir}/usr/share/doc/${pkgname}/README.md"
}
