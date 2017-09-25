import QtQuick 2.7

Canvas {
    property color color: "grey"
    property real signalStrength: 1
    property int levels: 4

    onPaint: {
        var ctx = getContext("2d")

        var r = (height-2) / (levels*2 + 1)
        var halfAngle = Math.asin((width-2)/2/(r*(levels*2 + 0.5)))
        var angleStart = -0.5*Math.PI - halfAngle
        var angleEnd = -0.5*Math.PI + halfAngle

        ctx.fillStyle = color
        ctx.strokeStyle = color
        ctx.lineWidth = r

        ctx.ellipse((width-r)/2, height-r-1, r, r)
        ctx.fill()

        for(var i = 1; i <= Math.min(Math.round(signalStrength * levels), levels); i++) {
            ctx.beginPath()
            ctx.arc(width/2, height-r/2-1, 2*i*r, angleStart, angleEnd)
            ctx.stroke()
        }
    }
}
