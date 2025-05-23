# shellcheck shell=bash
# shellcheck disable=SC2034

pkgname=guid
pkgver=r71.968836b
pkgrel=1
pkgdesc="Create advanced cross-platform GUI dialogs from the command line"
arch=('i686' 'x86_64')
url="https://github.com/jpfleury/guid"
license=('GPL')
depends=('qt5-base')
makedepends=('git' 'gcc')

pkgver() {
	git describe --tags --always --dirty | sed 's/-/./g'
}

build() {
	qmake-qt5 ..
	make
}

package() {
	# shellcheck disable=SC2154
	install -Dm755 guid -t "$pkgdir/usr/bin"
}
