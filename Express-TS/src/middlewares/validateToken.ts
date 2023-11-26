import { Response, Request, NextFunction } from 'express'
import { validateToken } from '../libs/token.libs.ts'
import { UserToken } from '../types/types'

interface RequestWithUserData extends Request {
  userData?: UserToken
}

export const authRequired = async (
  req: RequestWithUserData,
  res: Response,
  next: NextFunction
) => {
  try {
    const { token } = req.cookies

    if (!token) {
      return res.status(401).json({
        message: 'No token, authorization denied'
      })
    }

    const userDataToken: UserToken = await validateToken(token)
    req.userData = userDataToken

    next()
    return
  } catch (error) {
    console.error(error)
    return res.status(401).json({
      message: 'Unauthorized - Invalid token'
    })
  }
}
