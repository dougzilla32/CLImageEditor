// swift-tools-version: 6.0
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "CLImageEditor",
    defaultLocalization: "en", // Specify your default language (e.g., "en" for English)
    products: [
        // Products define the executables and libraries a package produces, making them visible to other packages.
        .library(
            name: "CLImageEditor",
            targets: ["CLImageEditor"]),
    ],
    dependencies: [
        // Dependencies declare other packages that this package depends on.
        // .package(url: /* package url */, from: "1.0.0"),
    ],
    targets: [
        // Targets are the basic building blocks of a package, defining a module or a test suite.
        // Targets can depend on other targets in this package and products from dependencies.
        .target(
            name: "CLImageEditor",
            dependencies: [],
            path: "Sources/CLImageEditor",
            publicHeadersPath: "include",
            cSettings: [
                .headerSearchPath("include")
            ]
        ),
    ]
)
