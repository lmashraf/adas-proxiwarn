cc_library(
    name = "sensor",
    srcs = ["sensor/sensor.cpp"],
    hdrs = ["sensor/sensor.h"],
)

cc_binary(
    name = "collision_warning_system",
    srcs = ["main.cpp"],
    deps = [":sensor"],
)