package cs152.lab2

import chisel3._
import org.chipsalliance.cde.config.{Field, Config, Parameters}
import freechips.rocketchip.tile._
import freechips.rocketchip.subsystem._
import freechips.rocketchip.rocket.{RocketCoreParams, DCacheParams}

class WithSecrets extends Config((site, here, up) => {
  case TilesLocated(InSubsystem) => up(TilesLocated(InSubsystem), site) map {
    case tp: RocketTileAttachParams => tp.copy(tileParams = tp.tileParams.copy(
        dcache = tp.tileParams.dcache map {
          case dp: DCacheParams => dp.copy(nWays = 32)
        }))
    case other => other
  }
})
